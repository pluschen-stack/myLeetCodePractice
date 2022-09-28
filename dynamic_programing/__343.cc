#include "../defs.h"

class Solution
{
public:
    int integerBreak(int n)
    {
        //这题的数学分析有意思,，下面是知道结果后反推结论
        // You're making it pretty complicated.
        // If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without
        // losing optimality, as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4,
        // meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for
        // n=2 and n=3, where it's needed).
        // For the rest I agree, 3*3 is simply better than 2*2*2, so you'd never use 2 more than twice.
        // dp[i]表示i拆分后的最大乘积
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                //这一步要在乘j之前取max，我觉得原因在于2和3两个数的拆分是比两个数的乘积小的
                //而再往上的拆分就大于等于了。所以为了3成立要这样做。
                //当然正如代码随想录的解释，这样也更加符合dp定义。
                dp[i] = max(max(dp[i - j], (i - j)) * j, dp[i]);
            }
        }
        return dp[n];
    }
};