# Visual digits recognition on embedded system basing on neural networks
<p align="center">
  <img src="https://raw.githubusercontent.com/wiki/jakubwieczorek/DigitsRecognition/uC.jpg" width="500" />
</p>
## About 
To goal is to recognise individual handwritten digits (outside the MNIST database) in real time by the camera. The images are captured in Python, resized to the 28x28 size and sent to the embedded system through UART, where deep feed forward neural network is implemented. Detected digit is displayed on the 7 segment display. System provides two ways of preprocessing the images. Adaptive Gaussian thresholding with the help of Open CV's API and Otsu thresholding implemented from the basis both in pure Python and C (in embedded system). Desired preprocessing might be chosen in the main script of communication application.

## Requirements
1.  NUCLE-H743ZI2 board
2.  7 segment display
3.  Tensorflow 2

## Videos
1. https://youtu.be/160r1aK84-g OTSU thresholding, real time
2. https://youtu.be/Fwi876-QRW0    OTSU thresholding full resolution
3. https://youtu.be/UEzEBQmksbM    Adaptive thresholding

## Questions or need help?
Don't hesitate to send me an email on jakub.wieczorek0101@gmail.com.

## Copyright and license
This project is copyright to Jakub Wieczorek under the [MIT License](https://opensource.org/licenses/MIT).
