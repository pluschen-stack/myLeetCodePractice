#include "../defs.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices,int fee)
    {
        //本题关键就是在两个增区间之间，第一个区间的最高点如果比第二个区间的最低点不高于fee的话应该合并区间
        int profit = 0;
        int prev = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prev )
            
            {
                prev = prices[i];
            }
            if( prices[i-1] >= prices[i] && prices[i] >= prev){
                //判断当前点比上一个点小，但是小的不多
                continue;
            }
            if (prices[i] > prev+fee)
            {
                profit += prices[i] - prev - fee;
                prev = prices[i] - fee;
            }
        }
        return profit;
    }
};