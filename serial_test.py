import bpy
import sys
import time
import math
import decimal
import threading
sys.path.append("/Library/Python/2.7/site-packages")
import serial
ser = serial.Serial("/dev/tty.usbmodem14111", 9600)
x = ser.readline()
value = 0

def a_part():
    while True:
        if x == b'1\r\n':
            print(value)
            value = value + 0.5
            value = round(value, 3)
            bpy.context.object.rotation_euler[2] = value
            time.sleep(0.5)
def b_part():
    while True:
        if x == b'2\r\n':
            print(value)
            value = value - 0.5
            value = round(value, 3)
            bpy.context.object.rotation_euler[2] = value
            time.sleep(0.5)
def n_part():
    while True:
        if x == b'\n':
            print(value)

ser.close()

if __name__ == "__main__":
    thread_a = threading.Thread(target=a_part)
    thread_b = threading.Thread(target=b_part)

    thread_a.start()
    thread_b.start()
