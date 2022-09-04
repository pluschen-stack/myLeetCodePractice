#include"../defs.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t slow = 0;
        for(size_t i = 0; i < nums.size();i++){
            if(nums[i]!=val){
                nums[slow++]=nums[i];
            }
        }    
        return slow;    
    }
};