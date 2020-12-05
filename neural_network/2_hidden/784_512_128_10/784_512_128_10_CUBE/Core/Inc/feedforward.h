#ifndef FEED_FORWARD_H_
#define FEED_FORWARD_H_

#include<math.h>

extern const double seven[784];
extern const float w1[784][512];
extern const float w2[512][128];
extern const float w3[128][10];
extern const float b1[512];
extern const float b2[128];
extern const float b3[10];

void feedforward(const double x[], double z[], const float weights_matrix[], int ROW, int COL, const float biases[], double y[], double (*activationFunction)(double));
double ReLU(double x);
double sigmoid(double x);
void think(double x[], double y[], double z[]);

#endif
