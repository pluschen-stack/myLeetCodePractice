#include"../defs.h"

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex){
        if(sum>target) return;
        if(sum == target) ans.push_back(path);
        for(int i = startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum+candidates[i],i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        path.clear();
        backtracking(candidates,target,0,0);
        return ans;
    }
};