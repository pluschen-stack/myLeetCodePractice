#include"../defs.h"

class Solution {
private:
    bool backtracking(vector<int>& nums,int startIndex){
        //在leetcode上会超时，毕竟最差时间复杂度时O(n^(n-1)^(n-2)^(...))
        if(startIndex>=nums.size()-1){
            return true;
        }
        for(int i=1;i<=nums[startIndex];i++){
            if(backtracking(nums,startIndex+i)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        //看了贪心的解法，确实很简单。
        if(nums.size()==1) return true;
        bool flag = true;
        int pos0 = -1;
        for(int i = nums.size()-1;i>=0;i--){
            if(flag&&nums[i]==0){
                flag = false;
                pos0 = i;
            }else if(!flag&&((nums[i]+i>pos0)||(nums[i]+i==nums.size()-1))){
                //前面有数可以跳过记录的0的位置,后面的或是因为有可能0是最后一位
                flag = true;
                pos0 = -1;
            }
        }
        return flag;
    }
};