import otsu
import cv2
import numpy as np

if __name__ == "__main__":
    image = cv2.imread('7.jpg', cv2.IMREAD_GRAYSCALE)
    arr = np.asarray(image)
    arr2 = cv2.resize(arr, (28, 28))
    np.savetxt('./7_2.txt', arr2, fmt='%f')
    otsu.otsu(arr2)
