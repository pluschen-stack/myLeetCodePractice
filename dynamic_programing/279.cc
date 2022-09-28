#include"../defs.h"

class Solution {
public:
    int numSquares(int n) {
        //这题的数学定理挺神奇的 四平方和定理
        //记录完全平方数
        vector<int> perfectSquare;
        int j = 1;
        for(int i = 1; j <= n; i++){
            j = i*i;
            perfectSquare.push_back(j);
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i = 1;i <= n;i++){
            dp[i] = INT32_MAX;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j<perfectSquare.size();j++){
                if(perfectSquare[j]<=i){
                    dp[i] = min(dp[i],dp[i-perfectSquare[j]]+1);
                }
            }
        }
        return dp[n];
    }
};