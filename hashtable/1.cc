#include"../defs.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> map; 
        for(size_t i = 0;i<nums.size();i++){
            if(map.count(target-nums[i])){
                ans.emplace_back(map[target-nums[i]]);
                ans.emplace_back(i);
                
            }else{
                map[nums[i]]=i;
            }
        }
        return ans;
    }
};