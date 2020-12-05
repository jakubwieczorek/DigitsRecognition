import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
# written in tf 2.2.0
print(tf.__version__)


class FeedForward:
    def __init__(self):
        (self.train_data, self.train_labels), (self.test_data, self.test_labels) = keras.datasets.mnist.load_data()
        self.train_data = self.train_data / 255.0
        self.test_data = self.test_data / 255.0

        print("Train samples: ", len(self.train_data))
        print("Test samples: ", len(self.test_data))

    def showSomeData(self):
        f1 = plt.figure(1)
        plt.imshow(self.train_data[0])
        plt.colorbar()
        plt.grid(False)

        f2 = plt.figure(2, figsize=(10, 10))
        for i in range(25):
            plt.subplot(5, 5, i+1)
            plt.xticks([])
            plt.yticks([])
            plt.grid(False)
            plt.imshow(self.train_data[i], cmap=plt.cm.binary)  # in gray scale
        plt.show()

    def createModel(self):
        self.model = keras.Sequential([ # layers in sequence
                keras.layers.Flatten(input_shape=(28, 28)),
                keras.layers.Dense(128, activation="relu"),  # Dense means fully connected
                keras.layers.Dense(10, activation="sigmoid")
            ])
        self.model.compile(optimizer="adam", loss="sparse_categorical_crossentropy", metrics=["accuracy"])

    def trainModel(self, epochs_num, save=True):
        self.model.fit(self.train_data, self.train_labels, epochs=epochs_num)  # epochs reshuffles training data
        test_loss, test_acc = self.model.evaluate(self.test_data, self.test_labels)
        print("Accuracy", test_acc)

    def saveModel(self, path):
        self.model.save(path)

        # there are 3 layers, but only 2 set of w and b, so 
        # here layer[1].get_weights are weights between inputs and first hl
        w_num = 1
        
        for layer in self.model.layers[1:]: # 0th layer is Flatten 
            np.savetxt(path + '/w' + str(w_num) + '.txt', layer.get_weights()[0], fmt='%f')
            np.savetxt(path + '/b' + str(w_num) + '.txt', layer.get_weights()[1], fmt='%f')
            w_num += 1

    def loadModel(self, path):
        self.model = keras.models.load_model(path)

    def makeSomePrediction(self):
        prediction = self.model.predict(self.test_data)
        print(prediction[0])
        for i in range(5):
            plt.grid(False)
            plt.imshow(self.test_data[i], cmap=plt.cm.binary)
            plt.title("Prediction: " + str(np.argmax(prediction[i])))
            plt.show()

        #prediction = model.predict([test_data[7]])
        #print(prediction)


if __name__ == "__main__":
    nn = FeedForward()
    #nn.showSomeData()
    nn.createModel()
    nn.trainModel(5)
    nn.saveModel("./model")
    #nn.loadModel("./model")
    nn.makeSomePrediction()
    #nn.saveModel("./model")
