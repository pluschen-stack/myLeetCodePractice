#include"../defs.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i < dp.size();i++){
            dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]); 
        }
        return dp[dp.size()-1];
    }
};