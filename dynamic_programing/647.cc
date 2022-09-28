#include "../defs.h"

class Solution
{
public:
    int countSubstrings(string s)
    {
        //从我的初始dp版本优化后的结果，时间复杂度度不变，常数减了一点，不过还是没有达到leetcode上的最优
        //看了一眼最优怎么做，好吧不会。
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        int ans = s.size();
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < s.size() - i; j++)
            {
                if (s[j] == s[j + i])
                {
                    dp[j][j + i] = dp[j + 1][j + i - 1];
                    if (dp[j][j + i])
                    {
                        ans++;
                    }
                }
                else
                {
                    dp[j][j + i] = false;
                }
            }
        }
        return ans;
    }

    int countSubstringsOriginal(string s)
    {
        //我一开始用dp做出的版本
        // dp[i][j]表示从i到j是回文的概率。
        // dp[i][j] = s[i]==[j]?dp[i+1][j-1]:false;
        //最后数true的个数.
        //这题有意思的是斜向遍历
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < s.size() - i; j++)
            {
                if (s[j] == s[j + i])
                {
                    dp[j][j + i] = dp[j + 1][j + i - 1];
                }
                else
                {
                    dp[j][j + i] = false;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size() - i; j++)
            {
                if (dp[j][j + i])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};