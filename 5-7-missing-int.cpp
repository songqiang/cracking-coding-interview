/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

An array A[1...n] contains all the integers from 0 to n except for one
number which is missing. In this problem, we cannot access an entire
integer in A with a single opera- tion. The elements of A are
represented in binary, and the only operation we can use to access
them is “fetch the jth bit of A[i]”, which takes constant time. Write
code to find the missing integer. Can you do it in O(n) time?

 */


static size_t
get_missing_int(int [] a, int n)
{
    int s = 0;
    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= n_bits; ++j)
            s += get_bit(a, i, j) << (j -1);

    return n * (n + 1) / 2 - s;
}
