#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "gpio.h"
#include "board.h"

void app_main(void){
    gpio_init(LED1, GPIO_MODE_OUTPUT);
    gpio_init(LED2, GPIO_MODE_OUTPUT);
    while(1){
        gpio_toggle(LED1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        
        gpio_toggle(LED2);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}