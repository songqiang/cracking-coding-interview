/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Write a method to decide if two strings are anagrams or not.

 */

class Solution 
{
public:
    
    bool
    is_anagram(const string &s1, const string &s2)
    {
        if (s1.size() != s2.size()) return false;
        vector<int> counts(128, 0);
        for (size_t i = 0; i < s1.size(); ++i)
        {
            ++counts[s1[i]];
            --counts[s2[i]];
        }

        return std::find(counts.begin(), counts.end(),
                         [](const int i){return i != 0;})
            == counts.end();
    }
};
