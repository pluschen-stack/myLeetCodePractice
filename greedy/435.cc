#include "../defs.h"

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int sum = 0;
        int border = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if(border >= intervals[i][0]){
                sum++;
            }else{
                border = intervals[i][1];
            }
        }
        return sum;
    }
};