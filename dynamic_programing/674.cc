#include"../defs.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1]+1;
                ans = max(ans,dp[i]);
            }else{
                dp[i] = 1;
            }
        }
        return ans;
    }
};