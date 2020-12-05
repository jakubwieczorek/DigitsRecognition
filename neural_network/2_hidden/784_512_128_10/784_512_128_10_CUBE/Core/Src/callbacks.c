#include "stm32h7xx.h"
#include "service.h"
#include "stdlib.h"
#include "stdbool.h"

extern uint8_t Received[3];
extern UART_HandleTypeDef huart3;
extern double image[784];
extern volatile bool done;
extern volatile bool is_otsu;

int counter = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(Received[0] == 'a') {
		counter = 0;
	} else
	if(Received[0] == 'b') {
		done = true;
	} else
	if(Received[0] == 'O') {
		is_otsu = true;
	} else
	if(Received[0] == 'A') {
		is_otsu = false;
	} else {
		int value = atoi((const char*)Received);
		image[counter++] = (double)value;
	}

	HAL_UART_Receive_IT(&huart3, Received, 3);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
//	is_otsu = !is_otsu;
}
