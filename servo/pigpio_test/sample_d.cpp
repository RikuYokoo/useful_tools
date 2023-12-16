#include <pigpiod_if2.h>
#include <iostream>

int main(){
	uint32_t pin_num = 25;
	int state = pigpio_start(nullptr, nullptr);
	std::cout << "state = " << state << std::endl;
	if(state < 0){
		std::cout << "not initilized" << std::endl;
		return -1;
	}else{
		std::cout << "success" << std::endl;
		int mode = set_mode(state, pin_num, PI_OUTPUT);
		std::cout << mode << std::endl;
		if(mode != 0){
			std::cout << "not set mode" << std::endl;
			pigpio_stop(state);
			return -1;
		}
		int frequency = 50;
		std::cout << "set_frequency" << std::endl;
		int ret = set_PWM_frequency(state, pin_num, frequency);
		if ( ret < 0 )
		{
			std::cout << "error" << std::endl;
			gpio_write(state, pin_num, 0);
			pigpio_stop(state);
			return -1;
		}
		std::cout << "ret = " << ret << std::endl;
		time_sleep(2);
		for(int i=300;i<2400;i+=100){
			std::cout << i << std::endl;
			set_servo_pulsewidth(state, pin_num, i);
			

			//std::cout << "500" << std::endl;
			//set_servo_pulsewidth(state, pin_num, 500);
			/*
			time_sleep(2);
			std::cout << "1500" << std::endl;
			set_servo_pulsewidth(state, pin_num, 1500);
			*/
			time_sleep(1);
			//std::cout << "2000" << std::endl;
			//set_servo_pulsewidth(state, pin_num, 950);
			//time_sleep(0.5);
		}
		gpio_write(state, pin_num, 0);
		pigpio_stop(state);
	}
	return 0;
}
