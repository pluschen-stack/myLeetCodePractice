#include "../defs.h"

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        //跟找回文子串一样，甚至还简单。需要注意的点就是需要初始化为全0，
        //这是为了遇到S[i]==S[j],j-1<i+1时的的情况，此时对应的dp状态值因该为0。
        //此题的状态dp[i][j]表示的是i到j的最长回文子序列长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 0; j < s.size() - i; j++)
            {
                if (s[j] == s[j + i])
                {
                    dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
                }
                else
                {
                    dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
                }
            }
        }
        // for(int i = 0; i < s.size();i++){
        //     for(int j = 0; j < s.size();j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     printf("\n");
        // }
        return dp[0][s.size() - 1];
    }
};

int main()
{
    Solution s;
    s.longestPalindromeSubseq("bbbba");
}