#include "../defs.h"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int i = 1; i <= coins.size();i++){
            for(int j = coins[i-1];j <= amount;j++){
                dp[j] += dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
    int changeOld(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                //其实我这里写复杂了，参考上面的一维版本可知可以利用本轮前面的值。
                if (j >= coins[i - 1])
                {
                    int total = 0;
                    for (int temp = 1; temp * coins[i - 1] <= j; temp++)
                    {
                        total += dp[i - 1][j - temp * coins[i - 1]];
                    }
                    dp[i][j] = dp[i][j] + total;
                }
            }
        }
        return dp[coins.size()][amount];
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 5};
    s.change(5, a);
}