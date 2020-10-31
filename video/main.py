import cv2
from time import sleep

import math
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import ff

if __name__ == "__main__":
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        exit(1)

    nn2 = ff.FeedForward.load('./model')

    # https: // docs.opencv.org / master / d7 / d4d / tutorial_py_thresholding.html
    while True:
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        resized = cv2.resize(gray, (28, 28))
        trunc = cv2.adaptiveThreshold(resized, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 9)
        bitwise = cv2.bitwise_not(trunc)

        # np.savetxt('./aaa.txt', bitwise, fmt='%f')

        final = bitwise / 255.0
        cv2.imshow('aaa', final)

        # sleep(1)

        prediction = nn2.think(final.flatten())
        # print(prediction)
        print("Prediction: " + str(np.argmax(prediction)))

        keyCode = cv2.waitKey(1)
        if cv2.getWindowProperty('aaa', cv2.WND_PROP_VISIBLE) < 1:
            break

    cap.release()
    cv2.destroyAllWindows()
