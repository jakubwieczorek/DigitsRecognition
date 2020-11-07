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
        for i in range(0, 10):
            ser.write(("0" + str(i)).encode())
            print("0" + str(i))
            time.sleep(2)
