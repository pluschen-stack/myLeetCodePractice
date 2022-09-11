#include "../defs.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int prev = prices[0];
        for(int i = 1;i < prices.size();i++){
            if(prices[i]-prev>0){
                sum+=(prices[i]-prev);
            }
            prev = prices[i];
        }
        return sum;
    }
};