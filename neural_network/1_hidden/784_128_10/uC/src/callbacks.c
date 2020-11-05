#include "stm32h7xx.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	static uint8_t data[40]; // Tablica przechowujaca wysylana wiadomosc.
	uint8_t a = data[0];
}
