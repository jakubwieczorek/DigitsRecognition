#include"w1.h"
#include"w2.h"
#include"b1.h"
#include"b2.h"
#include"sample.h"
#include"sample2.h"
#include<math.h>
#include<stdio.h>

void test2(const double weights_matrix[], int row, int col)
{
	int i, j;
	for(i=0; i<row; i++){
        	for(j=0; j<col; j++){
            		printf("%f ", *(weights_matrix + i*col + j)); // or better: printf("%d ", *matrix++);
        	}
       		printf("\n");
	}
}

// weights_matrix[], not [][], because second dimension has to be specified
void feedforward(const double x[], double z[], const double weights_matrix[], int ROW, int COL, const double biases[], double y[], double (*activationFunction)(double))
{
	int o, i;
	double cur_w;

	for(o = 0; o < COL; o++)
	{
		for(i = 0; i < ROW; i++)
		{	
			cur_w = *(weights_matrix + i*COL + o);
			y[o] += cur_w * x[i];
		}
	
		z[o] = y[o] + biases[o];
	}

	for(o = 0; o < COL; o++)
	{
		y[o] = (*activationFunction)(z[o]);
	}
}

double ReLU(double x)
{
	if(x < 0) {
		return 0.0;
	} else {
		return x;
	}
}

double sigmoid(double x)
{
	return 1.0 / (1.0 + (double)exp(-x));
}

void think(double x[], double y[], double z[])
{
	double l1_output[128] = {0}, z1[128] = {0};
	feedforward(x        , z1, w1[0], 784, 128, b1, l1_output, &ReLU);
	feedforward(l1_output, z,  w2[0], 128, 10,  b2, y, &sigmoid);
}

int main(void)
{
	double y[10] = {0};
	double z[10] = {0};

	think(seven, y, z);

	for(int i = 0; i < 10; i++)
	{
		printf("%f\n", y[i]);
	}

	return 0;
}

