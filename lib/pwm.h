#pragma once
#include "timer.h"


// The user of this library should generally avoid using lower level dependancies in timer.
// The user should also note that gpio control of PB0 and PB1 should be avoided when PWM outputs are necessary

#define PWM_PORT_A OCR0A
#define PWM_PORT_B OCR0B

#define PWM_SCALAR_OFF TIMER_NO_RATE // This will stop clocking pwm
#define PWM_SCALAR_1 TIMER_SYSTEM_RATE
#define PWM_SCALAR_8 TIMER_SYSTEM_RATE_DIV_8
#define PWM_SCALAR_64 TIMER_SYSTEM_RATE_DIV_64
#define PWM_SCALAR_256 TIMER_SYSTEM_RATE_DIV_256
#define PWM_SCALAR_1024 TIMER_SYSTEM_RATE_DIV_1024





// These pwm options utilize the MAX mode of fast PWM.
// The tradeoff with the OCR0A compare mode of fast PWM is less frequency resolution but independant hardware duty cycle control among OC0A and OC0B pins since both compare registers will be used for pin toggles
// The tradeoff with fast PWM against phase correct PWM is that fast PWM allows for a higher frequencies than phase correct PWM, but the time of interrupt triggers is undesirable for applications which require actions at the center of high or low side phases.

// The pwm carrier frequency will be f_pwm = f_clkio/(N*256) where N is the chosen scalar
#define pwm_fast_max_mode_set_frequency_divider(N) timer_set_timer_rate(N)

// The set value for this call should be a uint8_t between 0 and 0xFF. It divides the pwm period into phase "on" time.
#define pwm_fast_max_mode_set_duty_cycle_divider(port, value) (port = (value))

// This "dont_invert" call is the default case means the TOV0 interrupt flag will be set on a rising edge of the pwm waveform. The rising edges of A and B waveforms are aligned. The OCRF0x flag will be set on the individual falling edges. 
#define pwm_fast_max_mode_dont_invert_A() timer_pwm_set_upcount_OC0A()
#define pwm_fast_max_mode_dont_invert_B() timer_pwm_set_upcount_OC0B()

// This "invert" call means the TOV0 interrupt flag will be set on a falling edge of the pwm waveform. The falling edges of A and B waveforms are aligned. The OCRF0x flag will be set on the individual rising edges.
#define pwm_fast_max_mode_invert_A() timer_pwm_set_downcount_OC0A()
#define pwm_fast_max_mode_invert_B() timer_pwm_set_downcount_OC0B()

#define pwm_use_fast_max_mode() set_waveform_generation_FAST_PWM_MAX_mode(); pwm_fast_max_mode_dont_invert_A(); pwm_fast_max_mode_dont_invert_B()

