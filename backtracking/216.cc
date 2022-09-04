#include"../defs.h"

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(int k,int n,int startIndex){
        if(path.size()==k){
            if(n==0){
                ans.push_back(path);
            }
            return;
        }
        if(n<startIndex){
            //这个剪枝的原因是如果n的值小于当前的起始索引，那么后面n就不会等于0了，可以直接剪枝了
            return;
        }
        for(int i = startIndex;i<=9-(k-path.size())+1;i++){
            path.push_back(i);
            backtracking(k,n-i,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        path.clear();
        backtracking(k,n,1);
        return ans;
    }
};
