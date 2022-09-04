#include "../defs.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        //删空格
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (idx != 0)
                    s[idx++] = ' ';
                int end = i;
                while (end < s.size() && s[end] != ' ')
                    s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - i), s.begin() + idx);
                i = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};