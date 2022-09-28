#include "../defs.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //感觉这个题最好的思路还是贪心，硬要dp很别扭
        //copy一个讨论区：动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
        int minPrice = INT32_MAX,ans = 0;
        for(int i = 0;i < prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            ans = max(ans,prices[i]-minPrice);
        }
        return ans;
    }
    int maxProfitBrute(vector<int> &prices)
    {
        //直接超时
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};