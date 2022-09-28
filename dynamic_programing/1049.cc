#include "../defs.h"

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        //此题LeetCode官方题解写的很好。确实应该利用一下数学工具做一些变换。
        //然后利用01背包问题的结论解题
        int totalWeight = 0;
        for (auto stone : stones)
        {
            totalWeight += stone;
        }
        int n = stones.size();
        int m = totalWeight / 2 + 1;
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++)
        {
            if (j < stones[0])
                dp[0][j] = 0;
            else
                dp[0][j] = stones[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j < stones[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }
        return totalWeight  - 2*dp[n - 1][m - 1] ;
    };
};
