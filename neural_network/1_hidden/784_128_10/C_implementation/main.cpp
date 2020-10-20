#include<iostream>
#include"w1.h"
#include"w2.h"
#include"b1.h"
#include"b2.h"

int main(void)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			printf("%f\n", w1[i][j]);
		}
	}

	return 0;
}
