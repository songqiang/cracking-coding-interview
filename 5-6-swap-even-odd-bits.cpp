/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Write a program to swap odd and even bits in an integer with as few
instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and
bit 3 are swapped, etc).

 */

static size_t
swap_bits(const size_t i)
{
    return ((i & 0xAAAA) >> 1) + ((i & 0x5555) << 1);
}

