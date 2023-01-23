#include "ADXL335.h"
#include "main.h"

namespace project
{
    ADXL335::ADXL335(ADC_HandleTypeDef *adc) : _adc(adc)
    {
        if (HAL_ADCEx_Calibration_Start(_adc, ADC_SINGLE_ENDED)) {
            Error_Handler();
        }

        if (HAL_ADC_Start_DMA(_adc,(uint32_t *)adcConvertedValues,ADC_VALUES) != HAL_OK)
        {
            Error_Handler();
        }
    }

    void
    ADXL335::read()
    {
        /* Start ADC conversion */
        /* Since sequencer is enabled in discontinuous mode, this will perform    */
        /* the conversion of the next rank in sequencer.                          */
        /* Note: For this example, conversion is triggered by software start,     */
        /*       therefore "HAL_ADC_Start()" must be called for each conversion.  */
        /*       Since DMA transfer has been initiated previously by function     */
        /*       "HAL_ADC_Start_DMA()", this function will keep DMA transfer      */
        /*       active.                                                          */
        HAL_ADC_Start(_adc);

        /* Wait for conversion completion before conditional check hereafter */
        HAL_ADC_PollForConversion(_adc, 10);
    }

    long
    ADXL335::x()
    {
        return map(adcConvertedValues[ADC_X_POS], ADC_X_MIN, ADC_X_MAX);
    }

    long
    ADXL335::y()
    {
        return map(adcConvertedValues[ADC_Y_POS], ADC_Y_MIN, ADC_Y_MAX);
    }

    long
    ADXL335::z()
    {
        return map(adcConvertedValues[ADC_Z_POS], ADC_Z_MIN, ADC_Z_MAX);
    }

    long
    ADXL335::map(uint16_t value, uint16_t min, uint16_t max)
    {
        return (long) (100 * ((double)value - (double)min) / ((double) max - (double) min));
    }
} // project