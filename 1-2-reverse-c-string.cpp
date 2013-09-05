/*
 * Song Qiang <qiang.song@usc.edu> 2013-02-16
 *
 */

/*

Implement an algorithm to determine if a string has all unique
characters. What if you can not use additional data structures?

 */

class Solution 
{
public:
    
    void
    reverse(char* str)
    {
        if (str)
        {
            char* h = str;
            char* t = str;
            while (*t) ++t;
            
            while (h < t) 
            {
                const char ch = *h;
                *h++ = *t;
                *t-- = ch;
            }
        }
    }
};
