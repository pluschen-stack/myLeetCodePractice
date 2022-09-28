#include "../defs.h"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        //感觉这题难在思考出本质是从末尾看出需要前面左，左上，上的编辑距离
        //此题可以使用一维数组进行优化，只需两个临时变量存储dp[i-1][j-1]与dp[i][j-1]即可
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution s;
    s.minDistance("a", "ab");
}