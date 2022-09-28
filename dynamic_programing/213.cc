#include"../defs.h"

class Solution {
private:
    int helper(vector<int> &nums,int start,int end){
        int size = end-start;
        vector<int> dp(size);
        int j = 0;
        dp[j++] = nums[start];
        for(int i = start+1;i < end;i++,j++){
            if(j>=2){
                dp[j] = max(dp[j-1],dp[j-2]+nums[i]);
            }else{
                dp[j] = max(dp[j-1],nums[i]);
            }
        } 
        return dp[size-1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helper(nums,0,nums.size()-1),helper(nums,1,nums.size()));
    }
};