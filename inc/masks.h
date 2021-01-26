#ifndef MASKS_H
#define MASKS_H

// Masks
unsigned int    mask_and_ret_ui     (const unsigned int   * const   mask, const unsigned int   * const  value);
unsigned short  mask_and_ret_s      (const unsigned short * const   mask, const unsigned short * const  value);
void            mask_and_ui         (const unsigned int   * const   mask,       unsigned int   * const  value);
void            mask_and_s          (const unsigned short * const   mask,       unsigned short * const  value);

unsigned int    mask_or_ret_ui      (const unsigned int   * const   mask, const unsigned int   * const  value);
unsigned short  mask_or_ret_s       (const unsigned short * const   mask, const unsigned short * const  value);
void            mask_or_ui          (const unsigned int   * const   mask,       unsigned int   * const  value);
void            mask_or_s           (const unsigned short * const   mask,       unsigned short * const  value);

unsigned int    mask_xor_ret_ui     (const unsigned int   * const   mask, const unsigned int   * const  value);
unsigned short  mask_xor_ret_s      (const unsigned short * const   mask, const unsigned short * const  value);
void            mask_xor_ui         (const unsigned int   * const   mask,       unsigned int   * const  value);
void            mask_xor_s          (const unsigned short * const   mask,       unsigned short * const  value);

// Bit shifts
void            bit_shift_right_ui  (unsigned int   * const         variable, const unsigned int   * const nb_of_bits);
void            bit_shift_right_s   (unsigned short * const         variable, const unsigned short * const nb_of_bits);
void            bit_shift_left_ui   (unsigned int   * const         variable, const unsigned int   * const nb_of_bits);
void            bit_shift_left_s    (unsigned short * const         variable, const unsigned short * const nb_of_bits);

// Bit forces
void            bit_force_one_ui    (unsigned int   * const         variable, const unsigned int   * const bit_position);
void            bit_force_one_s     (unsigned short * const         variable, const unsigned short * const bit_position);
void            bit_force_zero_ui   (unsigned int   * const         variable, const unsigned int   * const bit_position);
void            bit_force_zero_s    (unsigned short * const         variable, const unsigned short * const bit_position);

// Bit values
unsigned int    get_bit_value_ui    (const unsigned int   * const   variable, const unsigned int   * const bit_position);
unsigned short  get_bit_value_s     (const unsigned short * const   variable, const unsigned short * const bit_position);

// Odd / Even checks
unsigned int is_odd_ui(unsigned int i);/* {
    return i&1;
}*/
unsigned short is_odd_s(unsigned short s);/* {
    return s&1;
}*/

unsigned int is_even_ui(unsigned int i);/* {
    return i&0;
}*/
unsigned short is_even_s(unsigned short s);/* {
    return s&0;
}*/

// Stuff to know :
/*
    To force at 1 the 3 first bits and the last one of a variable n, unsigned int type, in a system where its size is 16 bits :
        n = n | 0xE001u;

    To force at 0 those same bits :
        n = n & ~0xE001u;

    For those 2 examples, we need to know the size of an unsigned int (16 bits).
    If we don't know it explicitly :
        unsigned int mask, size_of_ui;
        size_of_ui = sizeof(unsigned int) * CHAR_BITS;  // #include <limits.h> // CHAR_BITS
        mask = 0x7u << (size_of_ui - 3);    // the 3 first bits
        mask = mask | 0x1u;                 // last bit
*/


#endif // MASKS_H