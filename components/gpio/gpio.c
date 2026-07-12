// This file is for writing the code for each GPIO control function

#include "gpio.h"

// GPIO peripheral base is 0x3FF44000 on ESP32 (pins 0-31)
#define GPIO_OUT_REG           (*(volatile uint32_t *)0x3FF44004)
#define GPIO_OUT_W1TS_REG      (*(volatile uint32_t *)0x3FF44008)
#define GPIO_OUT_W1TC_REG      (*(volatile uint32_t *)0x3FF4400C)
#define GPIO_ENABLE_W1TS_REG   (*(volatile uint32_t *)0x3FF44024)
#define GPIO_ENABLE_W1TC_REG   (*(volatile uint32_t *)0x3FF44028)
#define GPIO_IN_REG            (*(volatile uint32_t *)0x3FF4403C)

void gpio_init(uint8_t pin, gpio_mode_t mode) {
    if (mode == GPIO_MODE_OUTPUT) {
        GPIO_ENABLE_W1TS_REG = (1 << pin);
    } else {
        GPIO_ENABLE_W1TC_REG = (1 << pin);
    }
}

void gpio_write(uint8_t pin, uint8_t level) {
    if (level) {
        GPIO_OUT_W1TS_REG = (1 << pin);
    } else {
        GPIO_OUT_W1TC_REG = (1 << pin);
    }
}

void gpio_toggle(uint8_t pin) {
    if (GPIO_OUT_REG & (1 << pin)) {
        GPIO_OUT_W1TC_REG = (1 << pin);
    } else {
        GPIO_OUT_W1TS_REG = (1 << pin);
    }
}

uint8_t gpio_read(uint8_t pin) {
    return (GPIO_IN_REG >> pin) & 0x1;
}

void gpio_set(uint8_t pin)   { gpio_write(pin, 1); }
void gpio_clear(uint8_t pin) { gpio_write(pin, 0); }

/*
#include "gpio.h"
#include "soc/gpio_reg.h"
#include "soc/gpio_struct.h"
#include "soc/io_mux_reg.h"
#include "soc/soc.h"

void gpio_init(uint8_t pin, gpio_mode_t mode){
if(mode==GPIO_MODE_OUTPUT){GPIO.enable_w1ts=(1<<pin);} //if mode=0, set 1 to the pin
else{GPIO.enable_w1tc=(1<<pin);} //else clear the pin bit
}

void gpio_write(uint8_t pin, uint8_t level){
if(level){GPIO.out_w1ts=(1<<pin);} //if level is 1, set 1 to the pin.
else{GPIO.out_w1tc=(1<<pin);} //else clear the pin bit
}

void gpio_toggle(uint8_t pin){
if(GPIO.out & (1<<pin)){GPIO.out_w1tc=(1<<pin);}// if the shifted with & pin out dont give 00000000, then clear the pin bit
else{GPIO.out_w1ts=(1<<pin);}// else set the pin bit
}

void gpio_read(uint8_t pin){
return (GPIO.in >> pin) & 0x1; //shift the pin in to 0th bit
}
*/
