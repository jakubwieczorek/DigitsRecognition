################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32h743xx.s 

OBJS += \
./startup/startup_stm32h743xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/HAL_Driver/Inc/Legacy" -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/Utilities/STM32H7xx_Nucleo_144" -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/inc" -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/CMSIS/device" -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/CMSIS/core" -I"/home/jakub/Documents/PyCharmProjects/numbers_detection/neural_network/1_hidden/784_128_10/uC/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


