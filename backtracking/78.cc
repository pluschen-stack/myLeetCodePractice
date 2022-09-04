#include "../defs.h"

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        ans.push_back(path);
        if(startIndex>=nums.size()){
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        backtracking(nums,0);
        return ans;
    }
};