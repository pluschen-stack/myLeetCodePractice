#include "../defs.h"

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size()-3; i++)
        {
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (size_t j = i + 1; j < nums.size()-2; j++)
            {
                if((long)nums[i]+nums[j]>target && nums[i]+nums[j]>=0){
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                size_t left = j + 1;
                size_t right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[left] + nums[right] > (long)target - nums[i] - nums[j])
                        right--;
                    else if ((long)nums[left] + nums[right] < (long)target - nums[i] - nums[j])
                        left++;
                    else
                    {
                        result.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> a{2, 2, 2, 2};
    s.fourSum(a, 8);
}