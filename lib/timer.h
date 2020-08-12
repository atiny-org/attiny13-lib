#pragma once
#include "bit_operations.h"
#include "gpio.h"


#define TIMER_NO_RATE 0 // Stop the timer
#define TIMER_SYSTEM_RATE 1
#define TIMER_SYSTEM_RATE_DIV_8 2
#define TIMER_SYSTEM_RATE_DIV_64 3
#define TIMER_SYSTEM_RATE_DIV_256 4
#define TIMER_SYSTEM_RATE_DIV_1024 5
#define TIMER_T0_FALLING_EDGE_RATE 6 // Clock source is external falling edge
#define TIMER_T0_RISING_EDGE_RATE 7 // Clock source is external rising edge

// Select the clock source to be used with the Timer/Counter. This will start ticking the counter
#define timer_set_timer_rate(timer_rate) assign_bit_range_2_0(TCCR0B, timer_rate)

// Set the value in the timer
#define timer_set_timer_value(value) (TCCR0B = (value))

#define timer_reset_timer_value() (timer_set_timer_value(0))

/*
WG_NORMAL_MODE 0 = 0 00
WG_CTC_MODE 2 = 0 10
WG_FAST_PWM_MODE_MAX 3 = 0 11
WG_FAST_PWM_MODE_OCR0A 7 = 1 11
WG_PHASE_CORRECT_PWM_MODE_MAX 1 = 0 01
WG_PHASE_CORRECT_PWM_MODE_OCR0A 5 = 1 01
*/

// Set the waveform generator to a mode of operation
// Have to do a weird manipulation here since the WG bits span two registers.
#define set_waveform_generation_NORMAL_mode() clear_bit_multiple(TCCR0A, 0x3); clear_bit3(TCCR0B)
#define set_waveform_generation_CTC_mode() assign_bit_range_1_0(TCCR0A, 0x2); clear_bit3(TCCR0B)
#define set_waveform_generation_FAST_PWM_MAX_mode() set_bit_multiple(TCCR0A, 0x3); clear_bit3(TCCR0B)
#define set_waveform_generation_FAST_PWM_OCR0A_mode() set_bit_multiple(TCCR0A, 0x3); set_bit3(TCCR0B)
#define set_waveform_generation_PWM_MAX_mode() assign_bit_range_1_0(TCCR0A, 0x1); clear_bit3(TCCR0B)
#define set_waveform_generation_PWM_OCR0A_mode() assign_bit_range_1_0(TCCR0A, 0x1); set_bit3(TCCR0B)

#define TIMER_OVERFLOW_INTERRUPT 1
#define TIMER_OUTPUT_COMPARE_MATCH_A_INTERRUPT 2
#define TIMER_OUTPUT_COMPARE_MATCH_B_INTERRUPT 3

#define unmask_timer_interrupt(timer_interrupt) set_bit(TIMSK0, timer_interrupt)
#define mask_timer_interrupt(timer_interrupt) clear_bit(TIMSK0, timer_interrupt)

// Write an 8 bit value that the timer should be compared against for interrupts and waveform generation
#define timer_write_output_compare_A(value_8b) ((OCR0A) = (value_8b))

// Write an 8 bit value that the timer should be compared against for interrupts and waveform generation
#define timer_write_output_compare_B(value_8b) ((OCR0B) = (value_8b))


// The OC0x pin is not controlled by the hardware timer when these are called
#define timer_disconnect_OC0A() clear_bit_multiple(TCCR0A, 0xC0)
#define timer_disconnect_OC0B() clear_bit_multiple(TCCR0A, 0x30)


// Non PWM Mode Compare Output Mode Adjustments

// The OC0x pin is toggled at each compare match. For CTC mode, timer = OCR0x. For Normal mode, timer = 0xFF.
#define timer_non_pwm_toggle_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); assign_bit_range_7_6(TCCR0A, 0x40)
#define timer_non_pwm_toggle_OC0B() gpio_set_as_output_multiple(GPIO_PB1_MASK); assign_bit_range_5_4(TCCR0A, 0x10)

// The OC0x pin is cleared at each compare match.
#define timer_non_pwm_clear_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); assign_bit_range_7_6(TCCR0A, 0x80)
#define timer_non_pwm_clear_OC0B() gpio_set_as_output_multiple(GPIO_PB1_MASK); assign_bit_range_5_4(TCCR0A, 0x20)

// The OC0x pin is set at each compare match
#define timer_non_pwm_set_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); set_bit_multiple(TCCR0A, 0x80)
#define timer_non_pwm_set_OC0B() gpio_set_as_output_multiple(GPIO_PB1_MASK); set_bit_multiple(TCCR0A, 0x20)


// PWM Mode Compare Output Mode Adjustments

// The OC0A pin is toggled at each compare match.
// This will only cause toggles in the non max mode.
// Otherwise the compare output is disconnected from OC0A.
#define timer_pwm_toggle_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); set_bitassign_bit_range_7_6(TCCR0A, 0x40)

// The OC0x pin is set until cleared at compare match when counting up.
// Then the 0C0x pin is set again when the counter reaches MAX for fast PWM.
// Otherwise the 0C0x pin is set again during a match at countdown for phase correct PWM.
#define timer_pwm_set_upcount_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); assign_bit_range_7_6(TCCR0A, 0x80)
#define timer_pwm_set_upcount_OC0B() gpio_set_as_output_multiple(GPIO_PB1_MASK); assign_bit_range_5_4(TCCR0A, 0x20)

// The OC0x pin is cleared until set at compare match when counting up.
// Then the 0C0x pin is cleared again when the counter reaches MAX for fast PWM.
// Otherwise the 0C0x pin is cleared again during a match at countdown for phase correct PWM.
#define timer_pwm_set_downcount_OC0A() gpio_set_as_output_multiple(GPIO_PB0_MASK); set_bit_multiple(TCCR0A, 0x80)
#define timer_pwm_set_downcount_OC0B() gpio_set_as_output_multiple(GPIO_PB1_MASK); set_bit_multiple(TCCR0A, 0x20)





