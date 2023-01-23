#include "main.h"
#include <Project/ADXL335.h>
#include <Project/UART.h>
#include <Project/projectMain.h>
#include "usart.h"
#include "adc.h"

void
projectMain()
{
    project::UART comm(&huart2);
    project::ADXL335 accelerometer(&hadc1);

    comm.send("Start Fetching accelerometer data\n");
    comm.send("=================================\n\n");

    while (true)
    {
        accelerometer.read();

        char accelerometer_info[100];
        snprintf(accelerometer_info, 100,
                "x : %ld, y : %ld, z : %ld\n",
                accelerometer.x(),
                accelerometer.y(),
                accelerometer.z()
        );
        comm.send(accelerometer_info);

        HAL_Delay(1000);
    }
}