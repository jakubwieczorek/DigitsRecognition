#include"feedforward.h"

void feedforward(const double x[], double z[], const float weights_matrix[], int ROW, int COL, const float biases[], double y[], double (*activationFunction)(double))
{
	int o, i;
	float cur_w;

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
	double l1_output[512] = {0}, z1[512] = {0};
	double l2_output[128] = {0}, z2[128] = {0};
	feedforward(x        , z1, w1[0], 784, 512, b1, l1_output, &ReLU);
	feedforward(l1_output, z2, w2[0], 512, 128, b2, l2_output, &ReLU);
	feedforward(l2_output, z,  w3[0], 128, 10,  b3, y, &sigmoid);
}
