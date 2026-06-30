// This file is for writing function names for GPIO control.
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum{           // We define this to be a enum.
    GPIO_MODE_INPUT =0, // This is set to be 0.
    GPIO_MODE_OUTPUT    // This is 1 by default.
}gpio_mode_t;

void gpio_init(uint8_t pin, gpio_mode_t mode);// U mention the pin number and the pinmode as the parameters.

void gpio_write(uint8_t pin, uint8_t level);  // U mention the pin number and the HIGH OR LOW thing.

void gpio_toggle(uint8_t pin);                // Whatever the current state is, flip it once.

void gpio_set(uint8_t pin);

void gpio_clear(uint8_t pin);

#endif
