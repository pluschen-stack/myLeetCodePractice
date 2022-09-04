#include "../defs.h"

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        //一个字符串能够被子串所重复构成，说明这个字符串的长度可以被整除，因此子串的长度一定是一半以下的.
        //同时因为这个字符串能被子串构成，所以子串一定是从开头的到字符串前一半的某个位置截止的字符串。
        //因此暴力解法时间复杂度O(n^2)
        //这个题目中更好的解题方法是将字符串翻倍然后掐头去尾找该字符串，能够将时间复杂度压缩到O(n)
        //还有一个解法是如果可以被重复构成，那么在kmp所构成的前缀表中，
        string doubleS = s + s;
        doubleS.erase(doubleS.begin());
        doubleS.erase(doubleS.end() - 1);
        if (doubleS.find(s) != std::string::npos)
            return true;
        return false;
    }
};