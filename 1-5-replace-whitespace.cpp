/*
 * Song Qiang <qiang.song@usc.edu> 2013-02-16
 *
 */

/*

Write a method to replace all spaces in a string with ‘%20’.

 */

class Solution 
{
public:
    
    void
    replace(char* str)
    {
        if (str == NULL) return;

        char* p = str;
        int n = 0;
        int nwhite = 0;
        while (*p)
        {
            ++n;
            nwhite += *p == ' ';
            ++p;
        }

        if (nwhite > 0)
        {
            char *p1 = str + n;
            char *p2 = str + n + 2 * nwhite;
            while (p1 >= str)
            {
                if (*p1 == ' ')
                {
                    *(p2--) = '0';
                    *(p2--) = '2';
                    *(p2--) = '%';
                    p1--;
                }
                else
                    *(p2--) = *(p1--);
            }
        }
    }
};
