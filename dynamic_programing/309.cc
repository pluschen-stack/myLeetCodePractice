#include"../defs.h"

class Solution {
public:
    int maxProfit(vector<int>& prices){
        //参考leetcode题解的三种状态
        //状态0：持有股票
        //状态1：没有持有股票，但是处于冷却期（说明前一天我持有了股票）
        //状态2：没有持有股票，但是未处于冷却期（可能是刚过了冷却期，或者之前就是未处于冷却期）
        vector<vector<int>> dp(prices.size(),vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][2] = 0;
        dp[0][1] = 0;
        for(int i = 1; i < prices.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
        }
        for(int i = 0; i < prices.size();i++){
            for(int j = 0; j < 3; j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        return max(dp[prices.size()-1][1],dp[prices.size()-1][2]);
    }

    int maxProfitOld(vector<int>& prices) {
        //此题我划分三个状态虽然通过了leetcode但是我都不太确定能通过
        //我划分的是3种状态，其实没什么道理，这道题我通过的莫名奇妙，没有参考价值，不值得学习
        //0：没有股票，今天抛售
        //1：持有股票
        //2：没有股票，冷却期
        vector<vector<int>> dp(prices.size(),vector<int>(3));
        dp[0][0] = 0;
        dp[0][2] = 0;
        dp[0][1] = -prices[0];
        for(int i  = 1; i < prices.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][2]-prices[i]);
            if(i>=2) dp[i][2] = max(dp[i-1][2],dp[i-2][1]+prices[i-1]);
        }
        for(int i = 0; i < prices.size();i++){
            for(int j = 0; j < 3; j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        return dp[prices.size()-1][0];
    }
};

int main(){
    Solution s;
    vector<int> prices{1,8,3,0,2};
    s.maxProfit(prices);
}