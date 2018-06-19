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


def test():
    print(x)
def action():
    test()

if __name__ == "__main__":
    thread_a = threading.Thread(target=action)
    thread_a.start()
