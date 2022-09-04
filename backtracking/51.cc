#include"../defs.h"

class Solution {
private:
    vector<vector<string>> ans;
    vector<bool> path;
    void backtracking(int n,int alreadyPlacedNum){
        if(alreadyPlacedNum==n){
            return;
        }
        for(int i = 0; i < n;i++){
            
            backtracking(n,alreadyPlacedNum+1);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        path.clear();
        ans.clear();
        path.resize(n);
    }
};