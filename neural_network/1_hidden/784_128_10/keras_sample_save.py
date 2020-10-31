#!/usr/bin/python3

import math
from random import random
import numpy as np
import csv
import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    
    (train_data, train_labels), (test_data, test_labels) = keras.datasets.mnist.load_data()

    #np.savetxt('./sample.txt', test_data[0].flatten() / 255.0, fmt='%f')
    np.savetxt('./sample.txt', test_data[0], fmt='%f')

    plt.grid(False) 
    plt.imshow(test_data[0], cmap=plt.cm.binary)
    plt.show()
