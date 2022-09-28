#include "../defs.h"

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        //多容量01背包问题，动态规划这边代码随想录的题解完全比不过官方易懂。
        //可以把每个物体的体积看作是二维的，值都是1
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        for(int i = 1;i<= strs.size();i++){
            int oneNum = 0;
            for(int m = 0;m<strs[i-1].size();m++){
                oneNum= oneNum+ (strs[i-1][m]=='1'?1:0);
            }
            int zeroNum = strs[i-1].size()-oneNum;
            for(int j = 0;j <= m;j++){
                for(int k = 0;k <= n;k++){
                    if(j < zeroNum || k < oneNum){
                        dp[i][j][k]=dp[i-1][j][k];
                    }else{
                        dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-zeroNum][k-oneNum]+1);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

int main(){
    Solution s;
    vector<string> s1 = {"10","0001","111001","1","0"};
    s.findMaxForm(s1,5,3);
}