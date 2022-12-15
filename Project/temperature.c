#include "temperature.h"
#include "stm32f3xx_ll_adc.h"

#include <stdint-gcc.h>
#include <stdio.h>
#include <string.h>

HAL_StatusTypeDef initADCTemperature(ADC_HandleTypeDef* hadc)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    // ADC_CHANNEL_TEMPSENSOR for internal temp sensor
    // In_8 in pinout is temperature (cf. datasheet of IHM07M1)
    // In_12 for potentiometer
    sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SingleDiff = ADC_SINGLE_ENDED;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    sConfig.OffsetNumber = ADC_OFFSET_NONE;
    sConfig.Offset = 0;

    return HAL_ADC_ConfigChannel(hadc, &sConfig);
}

static const uint32_t ADC_RESOLUTION = ADC_RESOLUTION_12B;
static const uint16_t* VREF = VREFINT_CAL_ADDR;

int32_t getTemperatureFromSensor(ADC_HandleTypeDef* hadc)
{
    int32_t Temperature = -273;

    // Start ADC Conversion
    SET_BIT(ADC_COMMON_REGISTER(hadc)->CCR, ADC1_CCR_TSEN);
    HAL_ADC_Start(hadc);
    if (HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY) == HAL_OK)
    {
        // Get The Result
        uint32_t VTS = HAL_ADC_GetValue(hadc);
        // Deactivate ADC
        HAL_ADC_Stop(hadc);
        CLEAR_BIT(ADC_COMMON_REGISTER(hadc)->CCR, ADC1_CCR_TSEN);
        // Convert To Temp In °C
        Temperature = __LL_ADC_CALC_TEMPERATURE(*VREF, VTS, ADC_RESOLUTION);
    }

    return Temperature;
}

void sendTemperature(UART_HandleTypeDef* huart, int32_t temp)
{
    char temperatureMessage[TEMPERATURE_MSG_SIZE] = {0};
    sprintf(temperatureMessage, "Temp = %ld C\r\n", temp);

    HAL_UART_Transmit(huart, (uint8_t*)temperatureMessage, strlen(temperatureMessage), 10);
    HAL_Delay(1000);
}
