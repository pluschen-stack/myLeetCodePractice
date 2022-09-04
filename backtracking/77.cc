#include "../defs.h"

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int n,int k,int startIndex){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i = startIndex;i<=n-(k-path.size())+1;i++){
            //n-(k-path.size())+1的目的是剪枝，因为如果后面的节点数如果不够需要的节点数，那么就没有遍历的必要了
            path.push_back(i);//前进
            backtracking(n,k,i+1);
            path.pop_back();//回溯
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        path.clear();
        backtracking(n,k,1);
        return ans;
    }
};