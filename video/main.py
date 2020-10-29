import cv2
from time import sleep

if __name__ == "__main__":
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        exit(1)

    while True:
        ret, img = cap.read()
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        gray = cv2.resize(gray, (28, 28)) / 255
        cv2.imshow('aaa', gray)

        keyCode = cv2.waitKey(1)
        if cv2.getWindowProperty('aaa', cv2.WND_PROP_VISIBLE) < 1:
            break

        # sleep(1)

    cap.release()
    cv2.destroyAllWindows()
