## Progress Log

### Day 2 - GPIO Driver

Topics covered:
- GPIO driver implementation
- GPIO initialization
- GPIO read/write
- GPIO toggle
- Board-specific pin mapping using `board.h`
- Controlling multiple LEDs using the GPIO driver

Files added:
- drivers/gpio.c
- drivers/gpio.h
- boards/board.h
- examples/multiple_led_control

Skills learned:
- Register-level GPIO programming
- Write-One-To-Set (W1TS) and Write-One-To-Clear (W1TC) registers
- Hardware abstraction using board configuration
- Reusable embedded drivers