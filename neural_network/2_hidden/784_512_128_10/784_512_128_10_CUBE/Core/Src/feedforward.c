#include"feedforward.h"

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

void think(const double x[], double y[], double z[])
{
	double l1_output[128] = {0}, z1[128] = {0};
	feedforward(x        , z1, w1[0], 784, 128, b1, l1_output, &ReLU);
	feedforward(l1_output, z,  w2[0], 128, 10,  b2, y, &sigmoid);
}
