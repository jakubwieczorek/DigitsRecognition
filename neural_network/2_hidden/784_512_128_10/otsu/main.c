#include<math.h>
#include<stdio.h>
#include"seven.h"
#include"7_2.h"

#define BINS_NUMBER 256

void calculate_histogram(int histogram[], double image[], int size) {
	for(int i = 0; i < size; i++) {
		histogram[(int)image[i]]++;
	}
}

void otsu(double image[], int size) {
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
	printf("threshold = %d\n", threshold);
	for(int i = 0; i < size; i++) {
		image[i] = image[i] > threshold ? 255 : 0;
	}
}

int main(void)
{
	otsu(seven2, 28*28);
	return 0;
}

