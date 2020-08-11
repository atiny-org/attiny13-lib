#pragma once


#define BIT0 0x1
#define BIT1 0x2
#define BIT2 0x4
#define BIT3 0x8
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

// Set a bit
#define set_bit(destination, bit) ((destination) |= (1 << (bit)))

// Clear a bit
#define clear_bit(destination, bit) ((destination) &= ~(1 << (bit)))

// Get a bit
#define get_bit(source, bit) ((source & (1 << (bit))) >> (bit))

// Set multiple bits given mask
#define set_bit_multiple(destination, mask) ((destination) |= (mask))

// Clear multiple bits given mask
#define clear_bit_multiple(destination, mask) ((destination) &= ~(mask))

// Get multiple bits given mask
#define get_bit_multiple(source, mask) (source & (mask))

// Sets a specific bit to 1
#define set_bit0(destination) ((destination) |= BIT0)
#define set_bit1(destination) ((destination) |= BIT1)
#define set_bit2(destination) ((destination) |= BIT2)
#define set_bit3(destination) ((destination) |= BIT3)
#define set_bit4(destination) ((destination) |= BIT4)
#define set_bit5(destination) ((destination) |= BIT5)
#define set_bit6(destination) ((destination) |= BIT6)
#define set_bit7(destination) ((destination) |= BIT7)

// Clears a specific bit to 0

#define NOT_BIT0 0xFE
#define NOT_BIT1 0xFD
#define NOT_BIT2 0xFB
#define NOT_BIT3 0xF7
#define NOT_BIT4 0xEF
#define NOT_BIT5 0xDF
#define NOT_BIT6 0xBF
#define NOT_BIT7 0x7F

#define clear_bit0(destination) ((destination) &= NOT_BIT0)
#define clear_bit1(destination) ((destination) &= NOT_BIT1)
#define clear_bit2(destination) ((destination) &= NOT_BIT2)
#define clear_bit3(destination) ((destination) &= NOT_BIT3)
#define clear_bit4(destination) ((destination) &= NOT_BIT4)
#define clear_bit5(destination) ((destination) &= NOT_BIT5)
#define clear_bit6(destination) ((destination) &= NOT_BIT6)
#define clear_bit7(destination) ((destination) &= NOT_BIT7)

// assign_bitrange_X_Y will take a value and assign it at destination bit X.
// An important assumption being made here for optimization is that the user provides the shifted value
// of correct length

#define clear_bitmask_0_0 NOT_BIT0

#define clear_bitmask_1_0 0xFC
#define clear_bitmask_1_1 NOT_BIT1

#define clear_bitmask_2_0 0xF8
#define clear_bitmask_2_1 0xF9
#define clear_bitmask_2_2 NOT_BIT2

#define clear_bitmask_3_0 0xF0
#define clear_bitmask_3_1 0xF1
#define clear_bitmask_3_2 0xF3
#define clear_bitmask_3_3 NOT_BIT3

#define clear_bitmask_4_0 0xE0
#define clear_bitmask_4_1 0xE1
#define clear_bitmask_4_2 0xE3
#define clear_bitmask_4_3 0xE7
#define clear_bitmask_4_4 NOT_BIT_4

#define clear_bitmask_5_0 0xC0
#define clear_bitmask_5_1 0xC1
#define clear_bitmask_5_2 0xC3
#define clear_bitmask_5_3 0xC7
#define clear_bitmask_5_4 0xCF
#define clear_bitmask_5_5 NOT_BIT_5

#define clear_bitmask_6_0 0x80
#define clear_bitmask_6_1 0x81
#define clear_bitmask_6_2 0x83
#define clear_bitmask_6_3 0x87
#define clear_bitmask_6_4 0x8F
#define clear_bitmask_6_5 0x9F
#define clear_bitmask_6_6 NOT_BIT_6

// #define clear_bitmask_7_0 0x80 Just assign 0 instead...
#define clear_bitmask_7_1 0x01
#define clear_bitmask_7_2 0x03
#define clear_bitmask_7_3 0x07
#define clear_bitmask_7_4 0x0F
#define clear_bitmask_7_5 0x1F
#define clear_bitmask_7_6 0x3F
#define clear_bitmask_7_7 NOT_BIT_7

#define assign_bit_range_0_0(destination, value) ((destination) = ((destination)&clear_bitmask_0_0) | ((value)))
#define assign_bit_range_1_0(destination, value) ((destination) = ((destination)&clear_bitmask_1_0) | ((value)))
#define assign_bit_range_1_1(destination, value) ((destination) = ((destination)&clear_bitmask_1_1) | ((value)))
#define assign_bit_range_2_0(destination, value) ((destination) = ((destination)&clear_bitmask_2_0) | ((value)))
#define assign_bit_range_2_1(destination, value) ((destination) = ((destination)&clear_bitmask_2_1) | ((value)))
#define assign_bit_range_2_2(destination, value) ((destination) = ((destination)&clear_bitmask_2_2) | ((value)))
#define assign_bit_range_3_0(destination, value) ((destination) = ((destination)&clear_bitmask_3_0) | ((value)))
#define assign_bit_range_3_1(destination, value) ((destination) = ((destination)&clear_bitmask_3_1) | ((value)))
#define assign_bit_range_3_2(destination, value) ((destination) = ((destination)&clear_bitmask_3_2) | ((value)))
#define assign_bit_range_3_3(destination, value) ((destination) = ((destination)&clear_bitmask_3_3) | ((value)))
#define assign_bit_range_4_0(destination, value) ((destination) = ((destination)&clear_bitmask_4_0) | ((value)))
#define assign_bit_range_4_1(destination, value) ((destination) = ((destination)&clear_bitmask_4_1) | ((value)))
#define assign_bit_range_4_2(destination, value) ((destination) = ((destination)&clear_bitmask_4_2) | ((value)))
#define assign_bit_range_4_3(destination, value) ((destination) = ((destination)&clear_bitmask_4_3) | ((value)))
#define assign_bit_range_4_4(destination, value) ((destination) = ((destination)&clear_bitmask_4_4) | ((value)))
#define assign_bit_range_5_0(destination, value) ((destination) = ((destination)&clear_bitmask_5_0) | ((value)))
#define assign_bit_range_5_1(destination, value) ((destination) = ((destination)&clear_bitmask_5_1) | ((value)))
#define assign_bit_range_5_2(destination, value) ((destination) = ((destination)&clear_bitmask_5_2) | ((value)))
#define assign_bit_range_5_3(destination, value) ((destination) = ((destination)&clear_bitmask_5_3) | ((value)))
#define assign_bit_range_5_4(destination, value) ((destination) = ((destination)&clear_bitmask_5_4) | ((value)))
#define assign_bit_range_5_5(destination, value) ((destination) = ((destination)&clear_bitmask_5_5) | ((value)))
#define assign_bit_range_6_0(destination, value) ((destination) = ((destination)&clear_bitmask_6_0) | ((value)))
#define assign_bit_range_6_1(destination, value) ((destination) = ((destination)&clear_bitmask_6_1) | ((value)))
#define assign_bit_range_6_2(destination, value) ((destination) = ((destination)&clear_bitmask_6_2) | ((value)))
#define assign_bit_range_6_3(destination, value) ((destination) = ((destination)&clear_bitmask_6_3) | ((value)))
#define assign_bit_range_6_4(destination, value) ((destination) = ((destination)&clear_bitmask_6_4) | ((value)))
#define assign_bit_range_6_5(destination, value) ((destination) = ((destination)&clear_bitmask_6_5) | ((value)))
#define assign_bit_range_6_6(destination, value) ((destination) = ((destination)&clear_bitmask_6_6) | ((value)))
#define assign_bit_range_7_0(destination, value) ((destination) = ((destination)&clear_bitmask_7_0) | ((value)))
#define assign_bit_range_7_1(destination, value) ((destination) = ((destination)&clear_bitmask_7_1) | ((value)))
#define assign_bit_range_7_2(destination, value) ((destination) = ((destination)&clear_bitmask_7_2) | ((value)))
#define assign_bit_range_7_3(destination, value) ((destination) = ((destination)&clear_bitmask_7_3) | ((value)))
#define assign_bit_range_7_4(destination, value) ((destination) = ((destination)&clear_bitmask_7_4) | ((value)))
#define assign_bit_range_7_5(destination, value) ((destination) = ((destination)&clear_bitmask_7_5) | ((value)))
#define assign_bit_range_7_6(destination, value) ((destination) = ((destination)&clear_bitmask_7_6) | ((value)))
#define assign_bit_range_7_7(destination, value) ((destination) = (value))
