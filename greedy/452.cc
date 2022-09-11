#include "../defs.h"

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int sum = 1;
        int border = points[0][1];
        for(int i = 0; i < points.size();i++){
            if(points[i][0]<=border){
                continue;
            }else{
                sum++;
                border = points[i][1];
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    s.findMinArrowShots(points);
}