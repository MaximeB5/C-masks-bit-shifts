// My Includes
#include "../inc/masks.h"

// Includes
#include <stdio.h>
#include <limits.h>

// My Defines
	// None.

// Masks
unsigned int mask_and_ret_ui(const unsigned int * const value, const unsigned int * const mask)
{
	return *value & *mask;
}


unsigned short mask_and_ret_s(const unsigned short * const value, const unsigned short * const mask)
{
	return *value & *mask;
}


void mask_and_ui(unsigned int * const value, const unsigned int * const mask)
{
	*value = *value & *mask;
}


void mask_and_s(unsigned short * const value, const unsigned short * const mask)
{
	*value = *value & *mask;
}



unsigned int mask_or_ret_ui(const unsigned int * const value, const unsigned int * const mask)
{
	return *value | *mask;
}


unsigned short mask_or_ret_s(const unsigned short * const value, const unsigned short * const mask)
{
	return *value | *mask;
}


void mask_or_ui(unsigned int * const value, const unsigned int * const mask)
{
	*value = *value | *mask;
}


void mask_or_s(unsigned short * const value, const unsigned short * const mask)
{
	*value = *value | *mask;
}



unsigned int mask_xor_ret_ui(const unsigned int * const value, const unsigned int * const mask)
{
	return *value ^ *mask;
}


unsigned short mask_xor_ret_s(const unsigned short * const value, const unsigned short * const mask)
{
	return *value ^ *mask;
}


void mask_xor_ui(unsigned int * const value, const unsigned int * const mask)
{
	*value = *value ^ *mask;
}


void mask_xor_s(unsigned short * const value, const unsigned short * const mask)
{
	*value = *value ^ *mask;
}



// Bit shifts
void bit_shift_right_ui(unsigned int * const variable, const unsigned int * const nb_of_bits)
{
	*variable = *variable >> *nb_of_bits;
}


void bit_shift_right_s(unsigned short * const variable, const unsigned short * const nb_of_bits)
{
	*variable = *variable >> *nb_of_bits;
}


void bit_shift_left_ui(unsigned int * const variable, const unsigned int * const nb_of_bits)
{
	*variable = *variable << *nb_of_bits;
}


void bit_shift_left_s(unsigned short * const variable, const unsigned short * const nb_of_bits)
{
	*variable = *variable << *nb_of_bits;
}



// Bit forces
/**
 * @brief Force the bit at the specified position to 1.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 */
void bit_force_one_ui(unsigned int * const variable, const unsigned int * const bit_position)
{
	*variable = *variable | (1u << *bit_position);
}


/**
 * @brief Force the bit at the specified position to 1.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 */
void bit_force_one_s(unsigned short * const variable, const unsigned short * const bit_position)
{
	*variable = *variable | (1u << *bit_position);
}


/**
 * @brief Force the bit at the specified position to 0.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 */
void bit_force_zero_ui(unsigned int * const variable, const unsigned int * const bit_position)
{
	*variable = *variable & ~(1u << *bit_position);
}


/**
 * @brief Force the bit at the specified position to 0.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 */
void bit_force_zero_s(unsigned short * const variable, const unsigned short * const bit_position)
{
	*variable = *variable & ~(1u << *bit_position);
}



// Bit values
/**
 * @brief Get the bit value at the specified position to 0.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 * @return unsigned int 
 */
unsigned int get_bit_value_ui(const unsigned int * const variable, const unsigned int * const bit_position)
{
	return ((*variable & (1u << *bit_position)) ? 1 : 0);
}


/**
 * @brief Get the bit value at the specified position to 0.
 * CAREFUL : the bit 'count' begins at index 0, so it means the number '4' is currently number '3' (because 0 1 2 3)
 * 
 * @param variable 
 * @param bit_position 
 * @return unsigned short 
 */
unsigned short get_bit_value_s(const unsigned short * const variable, const unsigned short * const bit_position)
{
	return ((*variable & (1u << *bit_position)) ? 1 : 0);
}



// Odd / Even checks
unsigned int is_odd_ui(const unsigned int * const i)
{
    return *i & 1;
}


unsigned short is_odd_s(const unsigned short * const s)
{
    return *s & 1;
}


unsigned int is_even_ui(const unsigned int * const i)
{
    return !is_odd_ui(i);
}


unsigned short is_even_s(const unsigned short * const s)
{
    return !is_odd_s(s);
}


void show_bits(const unsigned int * const variable)
{
    unsigned int i = 0;
	unsigned int four_counter = 1; 

    for( i = ( sizeof(unsigned int) * CHAR_BIT ); i > 0; i--, ++four_counter )
    {
       //putchar(*variable & (1u << i) ? '1' : '0');
	   	int k = *variable >> i;

		if (k & 1)
		printf("1");
		else
		printf("0");

	   if(four_counter == 4) {
		   putchar(' ');
		   four_counter = 0;
	   }
    }

    printf("\n");
}