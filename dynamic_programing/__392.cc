#include "../defs.h"

class Solution
{
public:
    bool isSubsequenceDp(string s, string t)
    {
        //这里预处理可以使得对于固定的t，对于大量（比如K个长度为n）的s串，时间复杂度为O(Kn+t|字符串字符集大小|)
        //否则事件复杂度可能是O(Km)
        //这题感觉有意思的就是利用dp做预处理
        //状态dp[i][j]表示在字符串t中i位置及以后字符j的位置
        vector<vector<int>> dp(t.size() + 1, vector<int>(26));
        for (int j = 0; j < 26; j++)
        {
            dp[t.size()][j] = t.size();
        }
        for (int i = t.size()-1; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
            {
                if (t[i] - 'a' == j)
                {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        int j = 0;
        //这个对于任意s都是通用的。
        for (int i = 0; i < s.size(); i++)
        {
            if ((j = dp[j][s[i] - 'a']+1) == t.size()+1)
            {
                return false;
            }
        }
        return true;
    }

    bool isSubsequenceDoublePointer(string s, string t)
    {
        //时间复杂度O(m)
        if (s.size() > t.size())
            return false;
        int fast = 0;
        int slow = 0;
        while (fast < t.size())
        {
            if (t[fast] == s[slow])
            {
                slow++;
            }
            fast++;
        }
        return slow == s.size();
    }
};

int main(){
    Solution s;
    s.isSubsequenceDp("abc","ahsdbasdc");
}