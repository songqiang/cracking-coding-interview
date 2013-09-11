/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

You are given two 32-bit numbers, N and M, and two bit positions, i
and j. Write a method to set all bits between i and j in N equal to M
(e.g., M becomes a substring of N located at i and starting at j).

EXAMPLE:

Input: N = 10000000000, M = 10101, i = 2, j = 6

Output: N = 10001010100

 */

int
replace(int n, int m, int i, int j)
{
    return n - (((n >> j) << (32 - (j - i + 1))) >> (32 - j)) + (m << i)
}
