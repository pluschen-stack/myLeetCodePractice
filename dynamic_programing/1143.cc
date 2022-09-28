#include"../defs.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //状态表示为dp[i][j]为看了nums1的前i个字符和nums2的前j个字符后最长的公共子序列的长度。
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1));
        for(int i = 1; i <= text1.size();i++){
            for(int j = 1; j <= text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for(int i = 0; i <= text1.size();i++){
            for(int j = 0; j<= text2.size();j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        return dp[text1.size()][text2.size()];
    }
};

int main(){
    Solution s;
    s.longestCommonSubsequence("bdcaba","abcbdba");
}