#include "../defs.h"

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> subSet;
    void backtracking(vector<int>& nums,int startIndex){
        ans.push_back(subSet);
        for(int i = startIndex;i<nums.size();i++){
            if(i!=startIndex&&nums[i]==nums[i-1]){
                continue;
            }
            subSet.push_back(nums[i]);
            backtracking(nums,i+1);
            subSet.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        subSet.clear();
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return ans;
    }
};