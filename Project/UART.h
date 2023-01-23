#ifndef FIRMWARE_UART_H
#define FIRMWARE_UART_H

#include <string>

extern "C"
{
#include "main.h"
#include "stm32f302x8.h"
#include "stm32f3xx_hal_def.h"
}

namespace project
{

class UART
    {
    public:
        explicit UART(UART_HandleTypeDef* huart);

        void send(const char* message, size_t len);
        void send(const char* message);

    private:
        UART_HandleTypeDef* _huart;
    };

} // namespace project

#endif // FIRMWARE_UART_H
