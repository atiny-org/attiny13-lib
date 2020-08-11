#pragma once

#include <avr/io.h>
#include <stdint.h>
#include "bit_operations.h"


// Use these as inputs to the following macros

#define GPIO_PB0 PB0
#define GPIO_PB1 PB1
#define GPIO_PB2 PB2
#define GPIO_PB3 PB3
#define GPIO_PB4 PB4
#define GPIO_PB5 PB5

// These calls all operate on a single pin at a time

// Designate a single pin as an output
#define gpio_set_as_output(pin) set_bit(DDRB, pin)

// Designate a single pin as an input
#define gpio_set_as_input(pin) clear_bit(DDRB, pin)

// Set a single pin
#define gpio_set_output(pin) set_bit(PORTB, pin)

// Clear a single pin
#define gpio_clear_output(pin) clear_bit(PORTB, pin)

// Read value from a single pin
#define gpio_read_value(pin) get_bit(PINB, pin)

// Enables pull up resistor on single pin configured as input.
#define enable_input_pull_up(pin) gpio_set_output(pin)

// Disables pull up resistor on a single pin configured as input.
#define disable_input_pull_up(pin) gpio_clear_output(pin)


// Use these as inputs to the following calls

#define GPIO_PB0_MASK BIT0
#define GPIO_PB1_MASK BIT1
#define GPIO_PB2_MASK BIT2
#define GPIO_PB3_MASK BIT3
#define GPIO_PB4_MASK BIT4
#define GPIO_PB5_MASK BIT5

// These calls all act on multiple pins synchronously

#define gpio_set_as_output_multiple(mask) set_bit_multiple(DDRB, mask)

#define gpio_set_as_input_multiple(mask) clear_bit_multiple(DDRB, mask)

#define gpio_set_output_multiple(mask)  set_bit_multiple(PORTB, mask)

#define gpio_clear_output_multiple(mask) clear_bit_multiple(PORTB, mask)

#define gpio_read_value_multiple(mask) get_bit_multiple(PORTB, mask)

// Enables pull up resistor on multiple pins configured as input.
#define enable_input_pull_up_multiple(mask) gpio_set_output_multiple(mask)

// Disables pull up resistor on a multiple pins configured as input.
#define disable_input_pull_up_multiple(mask) gpio_clear_output_multiple(mask)
