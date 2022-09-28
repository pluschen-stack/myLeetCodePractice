#include"../defs.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //这题难在于多状态的表示和转移，我没写出来，太菜了。
        //我把leetcode题解泛化了一下，我感觉这种多状态本质上就是在无限次的基础上添加一个维度。
        //专门用来表示使用了多少次的状态。感觉和混合背包问题有点类似。
        int k = 4;
        vector<vector<int>> dp(prices.size(),vector<int>(4));
        for(int i = 0; i < k;i++){
            if(i%2) dp[0][i] = 0;
            else dp[0][i] = -prices[0];
        }
        for(int i = 1; i < prices.size();i++){
            dp[i][0] = max(dp[i-1][0],-prices[i]);
            for(int j = 1; j < k;j++){
                if(j%2) dp[i][j] = max(dp[i-1][j],dp[i][j-1]+prices[i]);
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]-prices[i]);
            }
        }
        return dp[prices.size()-1][k-1];
    }
};

int main(){
    Solution s;
    vector<int> prices{3,3,5,0,0,3,1,4};
    s.maxProfit(prices);
}