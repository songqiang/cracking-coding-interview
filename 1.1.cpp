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
    
    // assuming characters are only from ASCII numbers
    // time complexity O(n)
    bool
    is_there_duplicates(string str)
    {
        const size_t ALPHABETA_TABLE_SIZE = 128; // ASCII character

        if (str.size() > ALPHABETA_TABLE_SIZE) return true;
        if (str.size() < 2) return false;
        
        vector<bool> occured(ALPHABETA_TABLE_SIZE, false);
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (occured[str[i]]) return true;
            occured[str[i]] = true;
        }

        return false;
    }

    // assuming the size of alphabeta table is undetermined or too big
    // time complexity O(nlog(n))
    bool
    is_there_duplicates(string str)
    {
        std::sort(str.begin(), str.end());
        for (size_t i = 1; i < str.size(); ++i)
            if (str[i - 1] == str[i]) return true;
        return false;
    }
};
