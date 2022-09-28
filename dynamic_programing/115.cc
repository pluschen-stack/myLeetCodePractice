#include"../defs.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp[i][j]表示看了t的前i个字符，s的前j个字符，t的前i个字符能够在s的前j个字符的不同序列数
        //最简单的情况i>j，那么dp[i][j]一定为0。
        //并且不难看出如果i=j，那么dp[i][j]要么等于1要么等于0，这取决于s[j]是否等于t[i]和dp[i-1][j-1]能不能为1
        //如果i<j,如果t[i]=s[j],那么就可以选择以这两个为终点符号的不同序列数加上以s[j-1]为终点符号的不同序列数
        //否则只能算上以s[j-1]为终点符号的不同序列数
        if(t.size()>s.size()) return 0;
        vector<vector<uint64_t>> dp(t.size()+1,vector<uint64_t>(s.size()+1));
        for(int j = 0;j <= s.size();j++){
            dp[0][j] = 1;
        }
        for(int i = 1; i <= t.size();i++){
            if(t[i-1]==s[i-1]){
                dp[i][i] = dp[i-1][i-1];
            }
            for(int j = i+1 ; j <= s.size();j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};

int main(){
    Solution s;
    s.numDistinct("rabbbit","rabbit");
}