#include "../defs.h"

class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> path;
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            string substr = s.substr(startIndex, i - startIndex + 1);
            if (isPalindrome(substr))
            {
                path.push_back(substr);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        ans.clear();
        path.clear();
        backtracking(s,0);
        return ans;
    }
};

int main()
{
    string s = "aab";
    Solution solution;
    vector<vector<string>> a = solution.partition(s);
    string a1 = "a[0][0];";
    cout << a1 << endl;
}