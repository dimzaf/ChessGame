import serial

arduino = serial.Serial('COM15', 9600)

while True:
    print(arduino.readline())