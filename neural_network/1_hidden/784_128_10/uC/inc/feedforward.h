#ifndef FEED_FORWARD_H_
#define FEED_FORWARD_H_

#include<math.h>

extern const double seven[784];
extern const double w1[784][128];
extern const double w2[128][10];
extern const double b1[128];
extern const double b2[10];

void feedforward(const double x[], double z[], const double weights_matrix[], int ROW, int COL, const double biases[], double y[], double (*activationFunction)(double));
double ReLU(double x);
double sigmoid(double x);
void think(double x[], double y[], double z[]);

#endif
