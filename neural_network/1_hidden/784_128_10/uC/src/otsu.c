#include<math.h>

#define BINS_NUMBER 256

void calculate_histogram(int histogram[], int image[], int size) {
	for(int i = 0; i < size; i++) {
		histogram[image[i]]++;
	}
}

void otsu(int image[], int size) {
	int histogram[BINS_NUMBER] = {0};
	calculate_histogram(histogram, image, size);

	float sum = 0;
	for(int i = 0; i < BINS_NUMBER; i++) {
		sum += i*histogram[i];
	}

	float sumB = 0, wB = 0, wF = 0, varMax = 0;
        int threshold = 0;
	for(int t = 0; t < size; t++) {
		wB += histogram[t];
		if(wB == 0) {
			continue;
		}
		wF = size - wB;

		if(wF == 0) {
			break;
		}
		sumB += (float)t*histogram[t];
		float mB = sumB / wB;
		float mF = (sum-sumB) / wF;
		float varBetween = wB * wF * (mB-mF)*(mB-mF);

		if(varBetween > varMax) {
			varMax = varBetween;
			threshold = t;
		}
	}

	for(int i = 0; i < size; i++) {
		image[i] = image[i] > threshold ? 0 : 255;
	}
}
