//
// Created by yatima on 14/12/22.
//

#ifndef FIRMWARE_SERIAL_H
#define FIRMWARE_SERIAL_H

extern "C" {
#include "main.h"
#include "stm32f302x8.h"
#include "stm32f3xx_hal_def.h"
}

namespace project
{

class Serial
{
public:
    explicit Serial(UART_HandleTypeDef* _huart);
    void send(const char* message);

private:
    UART_HandleTypeDef* huart;
};

} // namespace project

#endif // FIRMWARE_SERIAL_H
