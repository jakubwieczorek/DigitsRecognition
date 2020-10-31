/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32h7xx.h"
#include "feedforward.h"
#include "config.h"

int main(void)
{
	HAL_Init();
//
	__HAL_RCC_GPIOB_CLK_ENABLE();

	gpio_config();

//	double y[10] = {0};
//	double z[10] = {0};
//
//	think(seven, y, z);

	while(1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_Delay(1000);
	}

	return 0;
}
