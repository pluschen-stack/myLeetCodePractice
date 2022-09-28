#include "../defs.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        int n = nums.size();
        int m = sum / 2+1;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            if (i < nums[0])
                ans[0][i] = 0;
            else
                ans[0][i] = nums[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j < nums[i])
                    ans[i][j] = ans[i - 1][j];
                else
                    ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - nums[i]] + nums[i]);
            }
        }
        return ans[n - 1][m - 1] == sum / 2;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 11, 5};
    s.canPartition(nums);
}