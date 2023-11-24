#https://www.mechatronahibi.com/rpi-gpio-pwm/
#https://monoist.itmedia.co.jp/mn/articles/1605/12/news007_2.html
import RPi.GPIO as GPIO
import time

pin1_pwm = 32 # GPIO12
GPIO.setmode(GPIO.BOARD)

GPIO.setup(pin1_pwm, GPIO.OUT)

pwm = GPIO.PWM(pin1_pwm, 50) #(pin, Hz)

pwm.start(10)
time.sleep(1)
pwm.ChangeFrequency(20)
time.sleep(1)
pwm.ChangeFrequency(30)
time.sleep(1)
