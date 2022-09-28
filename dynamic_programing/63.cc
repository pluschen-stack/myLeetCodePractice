#include"../defs.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> ans(obstacleGrid.size(),vector<int>(obstacleGrid[0].size()));
        ans[0][0] = 1;
        for(int i = 1;i<ans[0].size();i++){
            if(obstacleGrid[0][i]==1) ans[0][i]=0;
            else ans[0][i] = ans[0][i-1];
        }
        for(int i = 1;i<ans.size();i++){
            if(obstacleGrid[i][0]==1){
                ans[i][0]=0;
            }else{
                ans[i][0] = ans[i-1][0];
            }
            for(int j = 1;j<ans[0].size();j++){
                if(obstacleGrid[i][j]==1){
                    ans[i][j]=0;
                }else{
                    ans[i][j]=ans[i-1][j]+ans[i][j-1];
                }
            }
        }
        return ans[ans.size()-1][ans[0].size()-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> question{{0,0}};
    s.uniquePathsWithObstacles(question);
}