#include "../defs.h"

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        unordered_set<int> mset;
        if (path.size() >= 2)
        {
            ans.push_back(path);
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (startIndex != 0 && nums[i] < nums[startIndex - 1]||mset.count(nums[i]))
            {
                continue;
            }
            mset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        backtracking(nums, 0);
        return ans;
    }
};