// My Includes
#include "../inc/masks.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
	// None for the moment.

int main()
{
	printf("Hello from C-Masks-Bit-Shifts.\n\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("--- TEST MASK ---\n\n");

	unsigned int dec_i 			= 25;	// 0x19 ; 0001 1001
	
	const unsigned int mask 	= 0x55;
	const unsigned int res_and	= 0x11;
	const unsigned int res_or	= 0x5D;
	const unsigned int res_xor	= 0x4C;

	if( mask_and_ret_ui(&dec_i, &mask) == res_and )	printf("ok mask_and_ret_ui\n");
	else 											printf("NOK mask_and_ret_ui\n");

	if( mask_or_ret_ui (&dec_i, &mask) == res_or )	printf("ok mask_or_ret_ui\n");
	else 											printf("NOK mask_or_ret_ui\n");

	if( mask_xor_ret_ui(&dec_i, &mask) == res_xor )	printf("ok mask_xor_ret_ui\n");
	else 											printf("NOK mask_xor_ret_ui\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("\n--- TEST Bit shifts ---\n\n");

	unsigned nb_bits			= 3;
	unsigned bit_shift 			= 0b01100010;
	const unsigned res_left		= 0b01100010000;
	const unsigned res_right	= 0b01100010;

	bit_shift_left_ui (&bit_shift, &nb_bits);
	if( bit_shift == res_left )						printf("ok bit_shift_left_ui\n");
	else 											printf("NOK bit_shift_left_ui\n");

	bit_shift_right_ui(&bit_shift, &nb_bits);
	if( bit_shift == res_right )					printf("ok bit_shift_right_ui\n");
	else 											printf("NOK bit_shift_right_ui\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("\n--- TEST Bit forces ---\n\n");

	unsigned data		= 0b1000;
	unsigned force		= 3;
	const unsigned res0	= 0b0000;
	const unsigned res1	= 0b1000;

	bit_force_zero_ui (&data, &force);
	if( data == res0 )								printf("ok bit_force_zero_ui\n");
	else 											printf("NOK bit_force_zero_ui\n");

	bit_force_one_ui(&data, &force);
	if( data == res1 )								printf("ok bit_force_one_ui\n");
	else 											printf("NOK bit_force_one_ui\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("\n--- TEST Bit values ---\n\n");

	const unsigned value	= 0b01100010;
	const unsigned pos0		= 4;
	const unsigned pos1		= 5;
	const unsigned respos0	= 0;
	const unsigned respos1	= 1;

	if( get_bit_value_ui (&value, &pos0) == respos0 )	printf("ok get_bit_value_ui '0'\n");
	else 												printf("NOK get_bit_value_ui '0'\n");
	
	if( get_bit_value_ui (&value, &pos1) == respos1 )	printf("ok get_bit_value_ui '1'\n");
	else 												printf("NOK get_bit_value_ui '1'\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("\n--- TEST Odd / Even ---\n\n");

	const unsigned odd_data		= 0b1001;
	const unsigned even_data	= 0b1000;
	const unsigned r_true		= 1;
	const unsigned r_false		= 0;

	if( is_odd_ui (&odd_data) == r_true )				printf("ok is_odd_ui '1'\n");
	else 												printf("NOK is_odd_ui '1'\n");
	
	if( is_odd_ui (&even_data) == r_false )				printf("ok is_odd_ui '0'\n");
	else 												printf("NOK is_odd_ui '0'\n");

	if( is_even_ui (&even_data) == r_true )				printf("ok is_even_ui '1'\n");
	else 												printf("NOK is_even_ui '1'\n");
	
	if( is_even_ui (&odd_data) == r_false )				printf("ok is_even_ui '0'\n");
	else 												printf("NOK is_even_ui '0'\n");

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	printf("\n--- TEST show_bits ---\n\n");
	
	const unsigned int to_show	= 0b1011001;
	show_bits(&to_show);

	// ---------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------

	return(0);
}
