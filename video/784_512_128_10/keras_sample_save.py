#!/usr/bin/python3

import math
from random import random
import numpy as np
import csv
import tensorflow as tf
import cv2
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
import ff
import otsu

def saveJpg():
    fname = '7.jpg'
    image = cv2.imread('7.jpg', cv2.IMREAD_GRAYSCALE)
    arr = np.asarray(image)
    arr2 = cv2.resize(arr, (28, 28))
    trunc = cv2.adaptiveThreshold(arr2, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 9)
    bitwise = cv2.bitwise_not(trunc)
    np.savetxt('./7.txt', bitwise, fmt='%f')

    plt.grid(False)
    plt.imshow(bitwise, cmap=plt.cm.binary)
    plt.show()
    return bitwise

def showImages(columns, rows, images):
    fig = plt.figure(figsize=(columns*10, rows*10))
    for i in range(1, columns * rows + 1):
        fig.add_subplot(rows, columns, i)
        plt.imshow(images[i], cmap=plt.cm.binary)
    plt.show()

def saveKeras():
    (train_data, train_labels), (test_data, test_labels) = keras.datasets.mnist.load_data()

    #np.savetxt('./sample.txt', test_data[0].flatten() / 255.0, fmt='%f')
    np.savetxt('./sample.txt', test_data[0], fmt='%f')

    plt.grid(False)
    plt.imshow(test_data[0], cmap=plt.cm.binary)
    showImages(6, 1, train_data)

    images = []
    images.append(None)
    images.append(test_data[0])
    images.append(cv2.imread('7.jpg'))
    arr = np.asarray(cv2.imread('7.jpg', cv2.IMREAD_GRAYSCALE))
    arr2 = cv2.resize(arr, (28, 28))
    trunc = cv2.adaptiveThreshold(arr2, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 9)
    bitwise = cv2.bitwise_not(trunc)
    images.append(bitwise)
    images.append(otsu.my_otsu2(arr))
    images.append(cv2.resize(otsu.my_otsu2(arr), (28, 28)))

    showImages(5, 1, images)

    return test_data[0]

if __name__ == "__main__":
    
    my7 = saveJpg() / 255.0
    keras7 = saveKeras() / 255.0
    nn2 = ff.FeedForward.load('./model')
    prediction = nn2.think(my7.flatten())
    # print(prediction)
    print("Prediction: " + str(np.argmax(prediction)))
