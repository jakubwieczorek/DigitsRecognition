#include "stm32h7xx.h"

extern uint8_t Received[10];
extern UART_HandleTypeDef uart;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	static uint8_t data[40];
	uint8_t a = data[0];

	HAL_UART_Receive_DMA(&uart, Received, 10);
}
