//
// Created by yatima on 14/12/22.
//

#include "Led.h"

namespace project
{
Led::Led(GPIO_TypeDef* t_gpio, uint16_t t_pin): gpio(t_gpio), pin(t_pin)
{
}

void Led::on()
{
    HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_SET);
}

void Led::off()
{
    HAL_GPIO_WritePin(gpio, pin, GPIO_PIN_RESET);
}

void Led::toggle()
{
    HAL_GPIO_TogglePin(gpio, pin);
}

auto Led::state() -> bool
{
    return HAL_GPIO_ReadPin(gpio, pin);
}

} // namespace project