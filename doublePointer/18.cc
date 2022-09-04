#include "../defs.h"

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target && nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] + nums[i] > target && nums[j] + nums[i] > 0)
                {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    //这里一个小细节是=放到最后，这样可以减少比较次数，从100ms->76ms的结果
                    if ((long)nums[left] + nums[right] + nums[i] + nums[j] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[left] + nums[right] + nums[i] + nums[j] > target)
                    {
                        right--;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[left], nums[right], nums[j]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};