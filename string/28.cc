#include "../defs.h"

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        int pT[needle.size()];
        getPrefixTable(pT, needle);
        for (int i = 0, j = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = pT[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
    void getPrefixTable(int *pT, const string &pattern)
    {
        int j = 0;
        pT[j] = 0;
        for (int i = 1; i < pattern.size(); i++)
        {
            while (j > 0 && pattern[i] != pattern[j])
            {
                j = pT[j - 1];
            }
            if (pattern[i] == pattern[j])
            {
                pT[i] = j + 1;
                j++;
            }
            else
            {
                pT[i] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    int pT[10] = {0};
    string ass = "aaabaaabf";
    s.getPrefixTable(pT, ass);
    for (int i; i < 10; i++)
    {
        cout << pT[i] << endl;
    }
    cout << "hello world" << endl;
}