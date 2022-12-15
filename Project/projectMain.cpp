#include "main.h"
#include <Project/Led.h>
#include <Project/Serial.h>
#include <Project/projectMain.h>
#include <usart.h>

void projectMain()
{
    project::Serial comm(&huart2);

    while (true)
    {
        comm.send("Hello World !\r\n");
        HAL_Delay(1000);
    }
}
