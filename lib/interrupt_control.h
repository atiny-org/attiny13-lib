#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_operations.h"

// Must be called in order for any configurable interrupts to be enabled
#define enable_interrupt_use() sei()

// Disables all interrupts
#define disable_intterupt_use() cli()


// Enables PC (Pin Change) interrupts of any type.
// After this is set, unmasked PC interrupts will start firing accordingly.
#define enable_PC_interupts() set_bit5(GIMSK)

// Disables PC interrupts of any type
#define disable_PC_interrupts() clear_bit5(GIMSK)


// Use these as inputs to the following PCINT macros. 
// These can be OR'd together to configure multiple atomically

#define INT_PCINT0 BIT0
#define INT_PCINT1 BIT1
#define INT_PCINT2 BIT2
#define INT_PCINT3 BIT3
#define INT_PCINT4 BIT4
#define INT_PCINT5 BIT5

// Unmasks PCINT (Pin Change) interrupts for the given pin
#define unmask_PCINT_interrupt(pcint) set_bit_multiple(PCMSK, pcint)

// Masks PCINT (Pin Change) interrupts for the given pin
#define mask_PCINT_interrupt(pcint) clear_bit_multiple(PCMSK, pcint)
