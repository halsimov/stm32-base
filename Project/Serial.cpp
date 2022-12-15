//
// Created by yatima on 14/12/22.
//

#include <Project/Serial.h>
#include <cstring>

namespace project
{
Serial::Serial(UART_HandleTypeDef* _huart) : huart(_huart)
{
}

void Serial::send(const char* message)
{
    if (HAL_UART_Transmit(huart, (uint8_t*)message, static_cast<uint16_t>(strlen(message)), 10) != HAL_StatusTypeDef::HAL_OK) {
        assert_failed((uint8_t*)__FILE__, __LINE__);
    }
}

} // namespace project