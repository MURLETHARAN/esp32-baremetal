// This file is for writing the code for each GPIO control function

#include "gpio.h"

#include "soc/gpio_reg.h"
#include "soc/gpio_struct.h"
#include "soc/io_mux_reg.h"
#include "soc/soc.h"

void gpio_init(uint8_t pin,  gpio_mode_t mode){
    if(mode==GPIO_MODE_OUTPUT){
        //Enable output
        GPIO.enable_w1ts=(1<<pin);//if pin=4 then 00000000 --> 00001000
    }
    else{
        //Disable output
        GPIO.enable_w1tc = (1<<pin);//pin=4 00001000 --> 00000000
    }
}

void gpio_write(uint8_t pin, uint8_t level){
    if (level){
        GPIO.out_w1ts=(1<<pin);// set HIGH
    }
    else{
        GPIO.out_w1tc=(1<<pin);//set LOW
    }
}

void gpio_toggle(uint8_t pin){
    if(GPIO.out & (1<<pin)){// if non zero pin=4 00001000 --> 00000000
        GPIO.out_w1tc=(1<<pin);
    }
    else{
        GPIO.out_w1ts=(1<<pin); 
    }
}

uint8_t gpio_read(uint8_t pin){
    return (GPIO.in >> pin) & 0x1;
}

void gpio_set(uint8_t pin){
    gpio_set_level(pin, 1);
}

void gpio_clear(uint8_t pin){
    gpio_set_level(pin, 0);
}

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