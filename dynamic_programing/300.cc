#include"../defs.h"

class Solution {
public:

    int lengthOfLIS(vector<int>& nums){
        const int mx = 0x3f3f3f3f;
        vector<int> dp(nums.size(),mx);
        for(int i = 0; i < nums.size();i++){
            *std::upper_bound(dp.begin(), dp.begin() + nums.size(), nums[i]
                ,[](const int &a,const int &b){return a<=b;})= nums[i];
        }
        int ans = 0;
        while(ans!=nums.size()&&dp[ans] != mx) ans++;
        return ans;
    }
    int lengthOfLISOld(vector<int>& nums) {
        //状态dp[i]表示的是以nums[i]结尾的最长递增子序列长度
        //O(n^2)的复杂度
        vector<int> dp(nums.size());
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            dp[i] = 1;//每一次都是从1开始的
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,7,7,7,7,7,7};
    s.lengthOfLIS(nums);
}