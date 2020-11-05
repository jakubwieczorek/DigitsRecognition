import datetime
import time
import serial

if __name__ == "__main__":
    
    ser = serial.Serial(
        port='/dev/ttyACM0',
        baudrate=115200,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS
    )

    while True:
        ser.write("123".encode())
        print("aaa")
        time.sleep(2)
