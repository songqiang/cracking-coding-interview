/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Given an integer, print the next smallest and next largest number that
have the same number of 1 bits in their binary representation.

 */

// what does next smallest mean?
void
int_with_same_bits(int n)
{
    size_t n_bits = 0;
    while (n)
    {
        n_bits += n & 1;
        n  >> 1;
    }

    // next smallest:
    int s = 1;
    s <<= 1;
    for (size_t i = 0; i < n_bits - 1; ++i)
    {
        s <<= 1;
        s += 1;
    }
    cout << s << endl;

    // next largest
    int l = 0;
    for (size_t i = 0; i < n_bits - 1; ++i)
    {
        l += 1;
        l <<= 1;
    }
    l <<= 1;
    l += 1;
    l <<= (32 - n_bits - 1);
    cout << l << endl;
}
