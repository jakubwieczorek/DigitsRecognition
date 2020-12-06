import numpy as np

# http://www.labbookpages.co.uk/software/imgProc/otsuThreshold.html
# https://dsp.stackexchange.com/questions/15734/otsu-thresholding-why-minimum-within-class-variance-gives-the-optimum-thresh
# https://www.quora.com/What-is-within-class-variance-between-class-and-total-class-variance-in-digital-image-processing
def my_hostogram(gray, bins):
    """ pixel values has to be within bins range, otherwise index out of range, for example
        if pixel 400th has value 70, but bins are -> [0...40], then histogram[70] yields IOR
    """
    histogram = [0 for i in bins]
    for i in range(gray.shape[0]):
        for j in range(gray.shape[1]):
            histogram[gray[i][j]] = histogram[gray[i][j]] + 1

    return histogram

def my_sum(array):
    sum = 0
    for i in range(0, len(array)):
        sum += array[i]*i
    return sum

def otsu(gray):
    numberOfPixels = gray.shape[0] * gray.shape[1]
    bins = np.arange(0, 256)
    histogram = my_hostogram(gray, bins)
    sum = my_sum(histogram)
    sumB = 0
    # two classes B (background), F (foreground)
    wB = 0  # probability of B, that B and F are separated by threshold
    wF = 0

    varMax = 0  # maximum between class variance
    threshold = 0
    for t in range(0, numberOfPixels):
        wB += histogram[t]
        if wB == 0:
            continue
        wF = numberOfPixels - wB
        if wF == 0:
            break

        sumB += float((t * histogram[t]))
        mB = sumB / wB  # weighted mean of B
        mF = (sum - sumB) / wF
        varBetween = float(wB) * float(wF) * (mB - mF) ** 2  # current between class variance
        if varBetween > varMax:
            varMax = varBetween
            threshold = t

    final_img = gray.copy()
    print(threshold)
    final_img[gray > threshold] = 0
    final_img[gray < threshold] = 255

    return final_img