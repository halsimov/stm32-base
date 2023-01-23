//
// Created by yatima on 14/12/22.
//

#include <Project/UART.h>
#include <usart.h>
#include <cstring>

namespace project
{
    UART::UART(UART_HandleTypeDef* huart)
            : _huart(huart)
    {
    }

    void
    UART::send(const char *message, size_t len)
    {
        if (HAL_UART_Transmit(_huart, (uint8_t *) message, static_cast<uint16_t>(len), 100) !=
            HAL_StatusTypeDef::HAL_OK)
        {
            assert_failed((uint8_t *) __FILE__, __LINE__);
        }
    }

    void
    UART::send(const char* message)
    {
        send(message, strlen(message));
    }

} // namespace project