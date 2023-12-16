#include<pigpio.h>
#include <iostream>

int main(){
	int state = gpioInitialise();
	std::cout << "state = " << state << std::endl;
	if(state < 0){
		std::cout << "not initilized" << std::endl;
		return -1;
	}else{
		std::cout << "success" << std::endl;
	}
	return 0;
}
