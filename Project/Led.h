#ifndef FIRMWARE_LED_H
#define FIRMWARE_LED_H

#include <stm32f3xx_hal.h>

namespace project
{

    class Led
    {
    public:
        explicit Led(GPIO_TypeDef* t_gpio, uint16_t t_pin);

        void on();

        void off();

        void toggle();

        auto state() -> bool;

    private:
        GPIO_TypeDef* gpio;
        uint16_t pin;
    };

} // namespace project

#endif // FIRMWARE_LED_H
