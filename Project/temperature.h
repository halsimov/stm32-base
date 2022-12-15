#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "stm32f3xx_hal.h"

#define TEMPERATURE_MSG_SIZE 30

HAL_StatusTypeDef initADCTemperature(ADC_HandleTypeDef* hadc);
int32_t getTemperatureFromSensor(ADC_HandleTypeDef* hadc);
void sendTemperature(UART_HandleTypeDef* huart, int32_t temp);

#endif // End TEMPERATURE_H
