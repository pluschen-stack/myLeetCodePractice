#include"../defs.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //动态规划适合最值和数量等问题，因此如果要求所有的排列那么需要用到回溯进行暴力搜索了
        //如果nums中存在负数，那么就会有无穷多的答案。我觉得可以添加的限制是限制排列数。
        //这道题其实也可以看作是爬楼梯的拓展版本
        vector<int> dp(target+1);
        dp[0]=1;
        for(int j = 0;j <= target;j++){
            for(int i = 0;i < nums.size();i++){
                if (j>=nums[i])
                {
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};