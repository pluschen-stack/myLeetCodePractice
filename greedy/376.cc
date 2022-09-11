#include "../defs.h"

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        //这道题O(n)复杂度，就是比较当前值和前面的值，如果大并且需要大的就ans++，否则就把当前值作为下一次比较的前面的值。
        //贪心思路比较明显，这道题代码随想录用diff来表示想要大的还是小的确实写的挺简练的。
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
        {
            if (nums[0] != nums[1])
                return 2;
            else
                return 1;
        }
        int ans = 1;
        int prev = nums[0];
        int mode = 0;
        int i = 1;
        for (; i < nums.size(); i++)
        {
            if (nums[i] > prev)
            {
                ans++;
                mode = -1;
                prev = nums[i];
                break;
            }
            else if (nums[i] < prev)
            {
                ans++;
                mode = 1;
                prev = nums[i];
                break;
            }
        }
        for (; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                continue;
            }
            else if ((prev < nums[i]) && (mode == 1))
            {
                //想要更大的，并且nums[i]符合条件
                prev = nums[i];
                ans++;
                mode = -1; //接下来要小的
            }
            else if ((prev > nums[i]) && (mode == 1))
            {
                //想要更大的，但是nums[i]却小
                prev = nums[i];
            }
            else if ((prev < nums[i]) && (mode == -1))
            {
                //想要更小的，但是nums[i]却大
                prev = nums[i];
            }
            else
            {
                //想要更小的，并且nums[i]符合条件
                prev = nums[i];
                ans++;
                mode = 1; //接下来要大的。
            }
        }
        return ans;
    }
};