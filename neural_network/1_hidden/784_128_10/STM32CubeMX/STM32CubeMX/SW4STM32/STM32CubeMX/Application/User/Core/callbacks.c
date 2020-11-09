#include "stm32h7xx.h"
#include "service.h"
#include "stdlib.h"
#include "stdbool.h"

extern uint8_t Received[3];
extern UART_HandleTypeDef huart3;
extern double image[784];
extern volatile bool done;
int counter = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(Received[0] == 'a') {
		counter = 0;
	} else
	if(Received[0] == 'b') {
		done = true;
	} else {
		int value = atoi((const char*)Received);
		image[counter++] = ((double)value) / 255.0;
	}

	HAL_UART_Receive_IT(&huart3, Received, 3);
}
