import RPi.GPIO as GPIO

encoder_pin1 = 11
encoder_pin2 = 13

def getEncoder(channel):
    a = GPIO.input(encoder_pin1)
    b = GPIO.input(encoder_pin2)
    print(f"a, b = {a}, {b}")


GPIO.setmode(GPIO.BOARD)
GPIO.setup(encoder_pin1, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(encoder_pin2, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


GPIO.add_event_detect(encoder_pin1, GPIO.FALLING, callback=getEncoder, bouncetime=300)
GPIO.add_event_detect(encoder_pin2, GPIO.FALLING, callback=getEncoder, bouncetime=300)


input("aaaaaaaaaaaaaaaaaa\n")

GPIO.cleanup()
