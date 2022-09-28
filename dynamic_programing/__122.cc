#include"../defs.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //这里的状态表示和状态转移方程需要仔细思考其中的奥妙。
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[0]);
        }
        return dp[n-1][0];
    }
};