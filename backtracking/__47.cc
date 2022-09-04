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
            if (i != 0 && nums[i] == nums[i - 1] && used[i-1]==false)
            //第二个用来同一层去重，第三个保证树枝能往下走，因为树枝的时候他是true。
            {
                continue;
            }
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ans.clear();
        path.clear();
        vector<bool> used(nums.size());
        backtracking(nums, used);
        return ans;
    }
};