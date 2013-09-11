/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Write a function to determine the number of bits required to convert
integer A to integer B.

Input: 31, 14

Output: 2

 */


static size_t
get_n_bits(const size_t a, const size_t b)
{
    const size_t r = a ^ b;
    size_t n_bits = 0;
    while (r) 
    {
        n_bits += r & 1;
        r >>= 1;
    }
    return n_bits;
}
