import cv2
import numpy as np
from feedforward import FeedForward
import serial
from otsu import otsu

class Preprocessing():
    ADAPTIVE_THRESHOLD = 1
    OTSU = 2
    OTSU_ORIGINAL_IMAGE_NO_SERIAL = 3
    OTSU_EMBEDDED = 4

###################################################
# configuration part:
###################################################
SERIAL = True
PREPROCESSING = Preprocessing.ADAPTIVE_THRESHOLD

def adaptiveThreshold(img):
    resized = cv2.resize(gray, (28, 28))
    return cv2.adaptiveThreshold(resized, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 11, 9)

def adaptiveThresholdOriginal(img):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    resized = cv2.resize(gray, (28, 28))
    return cv2.adaptiveThreshold(resized, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 11, 9)

def send(ser, data, type):
    ser.write("aaa".encode())
    if type == Preprocessing.OTSU_EMBEDDED:
        ser.write("OOO".encode())
    else:
        ser.write("AAA".encode())

    for i in data.flatten():
        to_send = '{:3d}'.format(i)
        ser.write(to_send.encode())
    ser.write("bbb".encode())


if __name__ == "__main__":
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        exit(1)

    nn2 = FeedForward.load('./model')

    if PREPROCESSING != Preprocessing.OTSU_ORIGINAL_IMAGE_NO_SERIAL and SERIAL:
        ser = serial.Serial(
            port='/dev/ttyACM0',
            baudrate=115200,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS
        )

    while True:
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        if PREPROCESSING == Preprocessing.ADAPTIVE_THRESHOLD:
            resized = cv2.resize(gray, (28, 28))
            trunc_inv = cv2.adaptiveThreshold(resized, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 11, 9)
        elif PREPROCESSING == Preprocessing.OTSU:
            resized = cv2.resize(gray, (28, 28))
            trunc_inv = otsu(resized)
        elif PREPROCESSING == Preprocessing.OTSU_EMBEDDED:
            resized = cv2.resize(gray, (28, 28))
            trunc_inv = otsu(resized)
        elif PREPROCESSING == Preprocessing.OTSU_ORIGINAL_IMAGE_NO_SERIAL:
            trunc_inv = otsu(gray)

        if PREPROCESSING != Preprocessing.OTSU_ORIGINAL_IMAGE_NO_SERIAL and SERIAL:
            send(ser, trunc_inv, PREPROCESSING)

        final = trunc_inv / 255.0
        cv2.imshow('Video', final)

        if PREPROCESSING == Preprocessing.OTSU_ORIGINAL_IMAGE_NO_SERIAL: # resize for neural network
            final = cv2.resize(final, (28, 28))

        prediction = nn2.think(final.flatten())
        print("Prediction: " + str(np.argmax(prediction)))

        keyCode = cv2.waitKey(1)
        if cv2.getWindowProperty('Video', cv2.WND_PROP_VISIBLE) < 1:
            break

    cap.release()
    cv2.destroyAllWindows()
