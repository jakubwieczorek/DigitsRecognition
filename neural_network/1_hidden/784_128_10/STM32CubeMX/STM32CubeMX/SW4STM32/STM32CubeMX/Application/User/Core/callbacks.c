#include "stm32h7xx.h"
#include "service.h"
#include "stdlib.h"
extern uint8_t Received[2];
extern UART_HandleTypeDef huart3;

int ratoi(const char* a_source, int *result, char end_character)
{
	// char end_line = '\0';
    // size of source
    int size = 0;
    while(a_source[size++] != end_character);

    int i = 0;

    // parse int
    *result = 0;
    char letter;
    for(; a_source[i] != end_character; i++) {
        letter = a_source[i];

        if(letter > '9' || letter <'0') {
            return -1;
        }

        *result =  *result * 10 + a_source[i] - '0';
    }

    return 0;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//	int value;
//	ratoi(&Received, &value, Received);
	int value = atoi((const char*)Received);
	if( value != 0) {
		display_digit(atoi((const char*)Received));
	}

	HAL_UART_Receive_IT(&huart3, Received, 2);
}
