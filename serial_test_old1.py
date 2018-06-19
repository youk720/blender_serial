import bpy
import sys
import time
import decimal
sys.path.append("/Library/Python/2.7/site-packages")
import serial
ser = serial.Serial("/dev/tty.usbmodem14111", 9600)
x = ser.readline()
value = 0

while True:
    # print(x)
    #
    if x == b'1\r\n':
        value = value + 0.5
        value = round(value, 3)
        print(value)
        bpy.context.object.rotation_euler[2] = value
        time.sleep(0.1)

    if x == b'2\r\n':
        value = value - 0.5
        value = round(value, 3)
        print(value)
        bpy.context.object.rotation_euler[2] = value
        time.sleep(0.1)

ser.close()
