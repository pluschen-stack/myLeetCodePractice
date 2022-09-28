#include"../defs.h"

class Solution {
public:
    int numTrees(int n) {
        //这个题和进栈N个元素，出栈顺序的数量是同类型题目。
        //这题官方解答比代码随想录讲的更加的清晰
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};