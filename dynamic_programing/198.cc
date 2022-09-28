#include"../defs.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        //我的dp[i]表示的是在看了i间房子后，偷第i-1间房子最多能拿多少钱。
        //这题代码随想录的解答更好一些
        vector<int> dp(nums.size()+1);
        int ans = nums[0];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size();i++){
            for(int j = 0; j <= i-2; j++){
                dp[i] = max(dp[i],dp[j]+nums[i-1]);
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    s.rob(nums);
}
