#!/usr/bin/python3

import math
from random import random
import numpy as np
import csv
import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt


class FeedForward:
    def __init__(self, w1, b1, w2, b2, w3, b3):
        self.w1 = w1
        self.b1 = b1
        self.w2 = w2
        self.b2 = b2
        self.w3 = w3
        self.b3 = b3

    @classmethod
    def load(cls, path):
        w1 = np.loadtxt(path + '/w1.txt', dtype=float).tolist()
        b1 = np.loadtxt(path + '/b1.txt', dtype=float).tolist()
        w2 = np.loadtxt(path + '/w2.txt', dtype=float).tolist()
        b2 = np.loadtxt(path + '/b2.txt', dtype=float).tolist()
        w3 = np.loadtxt(path + '/w3.txt', dtype=float).tolist()
        b3 = np.loadtxt(path + '/b3.txt', dtype=float).tolist()

        if not isinstance(w3[0], list):  # if only one output, then wrap it into an array
            # so [1,2,3] -> [[1],[2],[3]]
            w3 = [[w3[i]] for i in range(len(w3))]

        if not isinstance(b3, list):  # if only one output, then wrap it into an array
            b3 = [b3]

        return cls(w1, b1, w2, b2, w3, b3)

    def feedForward(self, inputs, weights_matrix, biases, activationFunction):
        """
        weights_matrix should be [i][o]
            o
        i
            o
        i
            o
        i
            o
        biases should be [o_length]
        inputs should be [i_length]
        """
        input_length = len(weights_matrix)
        output_length = len(weights_matrix[0])
        x = inputs
        y = []
        z = []  # without activation

        for o in range(0, output_length):  # calculate each output in order
            y.append(0);
            z.append(0);
            for i in range(0, input_length):  # take ith weights from every input node
                y[o] += weights_matrix[i][o] * x[i]

            z[o] = y[o] + biases[o]

        for o in range(0, output_length):
            y[o] = activationFunction(z[o])

        return y, z

    def think(self, x):
        (self.l1_output, self.l1_z) = self.feedForward(x, self.w1, self.b1, self.ReLU)
        (self.l2_output, self.l2_z) = self.feedForward(self.l1_output, self.w2, self.b2, self.ReLU)
        (self.output, self.output_z) = self.feedForward(self.l2_output, self.w3, self.b3, self.sigmoid)
        return self.output

    def ReLU(self, x):  # it is actually LeakyReLU to tuckle with dying gradient
        # return max(0.1*x, x)
        return max(0, x)

    def softmax(self, x):
        # https://stats.stackexchange.com/questions/233658/softmax-vs-sigmoid-function-in-logistic-classifier
        pass

    def dSoftmax(self, x):
        pass

    def dReLU(self, x):
        # return 0.1 if x<0 else 1
        return 0 if x < 0 else 1

    def sigmoid(self, x):
        return 1 / (1 + math.exp(-x))

    def dSigmoid(self, sigm):
        return sigm * (1 - sigm)


if __name__ == "__main__":

    nn2 = FeedForward.load('./model')
    (train_data, train_labels), (test_data, test_labels) = keras.datasets.mnist.load_data()

    train_data = train_data / 255.0
    test_data = test_data / 255.0

    # print(test_data[0].shape)
    print()

    for i in range(20):
        plt.grid(False)
        plt.imshow(test_data[i], cmap=plt.cm.binary)
        prediction = nn2.think(test_data[i].flatten())
        print(prediction)
        plt.title("Prediction: " + str(np.argmax(prediction)))
        plt.show()