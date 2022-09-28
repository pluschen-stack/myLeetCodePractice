#include"../defs.h"

class Solution {
private:
    int ans = 0;
    void backtracking(vector<int>&nums,int neg,int startIndex){
        if(neg == 0){
            ans++;
        }
        if(neg < 0){
            return ;
        }
        for(int i = startIndex;i<nums.size();i++){
            backtracking(nums,neg-nums[i],i+1);
        }
    }

public:
    int findTargetSumWaysBackTracking(vector<int>& nums, int target) {
        //利用最后一块石头重量II的方法进行题目转换,这里是回溯的思路
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if((total-target)%2!=0){
            return 0;
        }
        //现在将求解目标转换为组合问题，即有多少组能够相加为neg
        int neg = (total-target)/2;
        backtracking(nums,neg,0);
        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //这是动态规划的思路
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if((total-target)<0||(total-target)%2!=0){
            return 0;
        }
        //现在将求解目标转换为组合问题，即有多少组能够相加为neg
        int neg = (total-target)/2;
        //这里设置遍历nums.size()是为了方便初始当背包容量为0时，不拿东西的情况。
        vector<vector<int>> dp(nums.size()+1,vector<int>(neg+1));
        dp[0][0] = 1;
        for(int i = 1;i<=nums.size();i++){
            for(int j = 0;j<neg+1;j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }
        return dp[nums.size()][neg];
    }
};

int main(){
    Solution s;
    vector<int> question = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    s.findTargetSumWays(question,1000);
}