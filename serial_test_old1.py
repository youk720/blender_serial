import bpy
import sys
import time
import decimal
sys.path.append("/Library/Python/2.7/site-packages")
import serial
ser = serial.Serial("/dev/tty.usbmodem14111", 9600)
value = bpy.context.object.rotation_euler[2]
try:
    while True:
        # print(x)
        # print(value)
        x = ser.readline()
        if x == b'1\r\n':
            value = value + 0.5
            value = round(value, 3)
            bpy.context.object.rotation_euler[2] = value
            print(value)
            time.sleep(0.1)
        elif x == b'2\r\n':
            value = value - 0.5
            value = round(value, 3)
            bpy.context.object.rotation_euler[2] = value
            print(value)
            time.sleep(0.1)
        pass
except KeyboardInterrupt:
    print(" ")
    print('interrupted!')
    print(bpy.context.object.rotation_euler[2] * 57.3)

pass
ser.close()
