import bpy
import sys
import time
import decimal
import string
sys.path.append("/Library/Python/2.7/site-packages")
import serial
ser = serial.Serial("/dev/tty.usbmodem14111", 9600)
value = bpy.context.object.rotation_euler[2]
try:
    while True:
        x = ser.readline()
        x_change = x.decode('utf-8')
        x_change = x_change.replace('\n','')
        x_change = x_change.replace('\r','')
        # 上はarduinoから出てきた出力にある改行文字を消している
        # print(x_change)
        value = value + (float(x_change))
        # 文字列扱いの数値を,扱えるように変換
        value = round(value, 3)
        bpy.context.object.rotation_euler[2] = value
        print(value)
        time.sleep(0.1)

except KeyboardInterrupt:
    print(" ")
    print('interrupted!')
    print(bpy.context.object.rotation_euler[2] * 57.3)

pass
ser.close()
