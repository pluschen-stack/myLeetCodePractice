#include"../defs.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //我直接把123.cc的题解略加修改就搬过来的，本题的空间复杂度还可以优化。但我懒得优化了。
        //这道题的思维感觉更重要一些。本质是划分k个区间峰值减去谷值的最大和。
        vector<vector<int>> dp(prices.size(),vector<int>(2*k));
        for(int i = 0; i < 2*k;i++){
            if(i%2) dp[0][i] = 0;
            else dp[0][i] = -prices[0];
        }
        for(int i = 1; i < prices.size();i++){
            dp[i][0] = max(dp[i-1][0],-prices[i]);
            for(int j = 1; j < 2*k;j++){
                if(j%2) dp[i][j] = max(dp[i-1][j],dp[i][j-1]+prices[i]);
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]-prices[i]);
            }
        }
        return dp[prices.size()-1][2*k-1];
    }
};