#include"../defs.h"

class Solution {
public:
    // void print(vector<vector<int>> & dp){
    //     for(int i = 0; i < dp.size();i++){
    //         for(int j = 0; j < dp[0].size();j++){
    //             printf("%d ",dp[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }
    int coinChange(vector<int>& coins, int amount) {
        //等待优化
        return 0;
    }
    int coinChangeOld(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        dp[0][0] = 0;
        for(int j = 1;j <= amount ; j++){
            dp[0][j] = -1;
        }
        for(int i = 1;i <= coins.size();i++){
            for(int j = 0; j <= amount;j++){
                if(j<coins[i-1]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    if(dp[i-1][j]==-1){
                        if(dp[i][j-coins[i-1]]==-1){
                            dp[i][j] = -1;
                        }else{
                            dp[i][j] = dp[i][j-coins[i-1]]+1;
                        }
                    }else{
                        if(dp[i][j-coins[i-1]]==-1){
                            dp[i][j] = dp[i-1][j];
                        }else{
                            dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                        }
                    }
                }
            }
        }
        // print(dp);
        return dp[coins.size()][amount];
    }
};

int main(){
    Solution s;
    vector<int> coins{2};
    cout<<s.coinChange(coins,3)<<endl;
}