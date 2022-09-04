#include "../defs.h"

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false)
            {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        //这道题因为nums.size()的规模很小，所以可以不使用vector<bool>而使用位运算来代替
        ans.clear();
        path.clear();
        vector<bool> used(nums.size());
        backtracking(nums, used);
        return ans;
    }
};