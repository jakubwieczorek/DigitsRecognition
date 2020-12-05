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

uint8_t Received[10];

int main(void) {
	HAL_Init();

	__HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_USART3_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

	gpio_config();
	uart_config();
	dma_config();
	nvic_config();

//	HAL_UART_Receive_DMA(&uart, Received, 10);


	double y[10] = {0};
	double z[10] = {0};
//
//	think(seven, y, z);

	test();

	uint8_t Data[50];
	int size = sprintf(Data, "START\n\r");

	while(1) {
		think(seven, y, z);

		display_digit(max_idx(y));

		HAL_UART_Transmit_IT(&uart, Data, size);

		HAL_Delay(1000);
	}

	return 0;
}
