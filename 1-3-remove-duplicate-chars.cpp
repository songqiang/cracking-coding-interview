/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Design an algorithm and write code to remove the duplicate characters
in a string without using any additional buffer. NOTE: One or two
additional variables are fine.  An extra copy of the array is not.

FOLLOW UP Write the test cases for this method.

 */

class Solution 
{
public:
    
    void
    remove_dup_char(char[] str)
    {
        if (str == NULL) return;
        
        char* h = str;
        char* t = str;
        while (*t) ++t;
        std::sort(h, t);

        t = h;
        while (*t)
        {
            if (*h == *t)
                ++t;
            else
                *(++h) = *(++t);
        }
        *(++h) = '\0';
    }

};
