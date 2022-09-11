#include"../defs.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        // 题解给的比我写的好多了
        if(nums.size()<=1) return 0;
        if(nums[0]>=nums.size()-1){
            return 1;
        }
        int step = 1;
        int k = nums[0];
        for(int i = 1;i<nums.size();i++){
            int temp = k;
            int j = i;
            for(;j <= temp;j++){
                k = max(k,j+nums[j]);
                if(k>=nums.size()-1){
                    j = nums.size();
                    break;
                }
            }
            i = j-1;
            step++;
        }
        return step;
    }
};