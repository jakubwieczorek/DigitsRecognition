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
#include "service.h"
#include "test.h"
#include<math.h>

int main(void) {
	HAL_Init();
//
	__HAL_RCC_GPIOB_CLK_ENABLE();

	gpio_config();

	double y[10] = {0};
	double z[10] = {0};
//
//	think(seven, y, z);

	test();

	while(1) {
		think(seven, y, z);

		display_digit(max_idx(y));

		HAL_Delay(1000);
	}

	return 0;
}
