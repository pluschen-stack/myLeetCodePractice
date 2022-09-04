#include "../defs.h"

class Solution
{
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> ans;

    void backtracking(string &digits, string path, int curIndex)
    {
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }
        for (auto c : letterMap[(int)(digits[curIndex] - '0')])
        {
            backtracking(digits, path + c, curIndex + 1);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        ans.clear();
        if(digits.size()==0) return ans; 
        backtracking(digits,"",0);
        return ans;
    }
};