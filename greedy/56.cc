#include "../defs.h"

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        int prev = 0;
        int right = intervals[prev][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (right >= intervals[i][0])
            {
                //重叠的区间
                right = max(right,intervals[i][1]);
            }
            else
            {
                ans.push_back({intervals[prev][0], right});
                prev = i;
                right = intervals[prev][1];
            }
        }
        //还有还没合并的
        ans.push_back({intervals[prev][0], right});
        return ans;
    }
};