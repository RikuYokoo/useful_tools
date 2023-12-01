#https://www.mechatronahibi.com/rpi-gpio-pwm/
#https://monoist.itmedia.co.jp/mn/articles/1605/12/news007_2.html
import RPi.GPIO as GPIO
import time

pin1_pwm = 32 # GPIO12
GPIO.setmode(GPIO.BOARD)

GPIO.setup(pin1_pwm, GPIO.OUT)

pwm = GPIO.PWM(pin1_pwm, 50) #(pin, Hz)

pwm.start(0)
time.sleep(2)

print("first")
pwm.ChangeDutyCycle(2)
time.sleep(2)
print("second")
pwm.ChangeDutyCycle(7)
time.sleep(2)
print("third")
pwm.ChangeDutyCycle(2)
time.sleep(2)

GPIO.cleanup()
