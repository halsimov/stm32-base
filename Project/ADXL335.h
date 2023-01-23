#ifndef FIRMWARE_ADXL335_H
#define FIRMWARE_ADXL335_H

#include <cstdint>
#include <stm32f3xx.h>

namespace project
{
    class ADXL335
    {
    public :
        explicit ADXL335(ADC_HandleTypeDef* adc);
        void read();
        long
        x();
        long
        y();
        long
        z();

    private :
        static const std::size_t ADC_VALUES = 3;

        static long map(uint16_t value, uint16_t min, uint16_t max);

        static const std::size_t ADC_X_POS = 0;
        static const uint16_t ADC_X_MIN = 1600;
        static const uint16_t ADC_X_MAX = 2420;

        static const uint16_t ADC_Y_POS = 1;
        static const uint16_t ADC_Y_MIN = 1600;
        static const uint16_t ADC_Y_MAX = 2420;

        static const uint16_t ADC_Z_POS = 2;
        static const uint16_t ADC_Z_MIN = 1600;
        static const uint16_t ADC_Z_MAX = 2420;

        ADC_HandleTypeDef* _adc;
        __IO uint16_t adcConvertedValues[ADC_VALUES];
    };

} // project

#endif //FIRMWARE_ADXL335_H
