#include "../defs.h"

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int startIndex)
    {
        if(target < 0){
            return;
        }
        if (target == 0)
        {
            ans.push_back(path);
        }
        for(int i = startIndex;i<candidates.size();i++){
            //在n数之和那里就是这样去重的
            //考虑的原理就是相同的数在前面的一次迭代中已经考虑过需要的情况了
            //那么第二次就不需要了。
            if(i!=startIndex&&candidates[i]==candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(candidates,target-candidates[i],i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        //这道题感觉就是一个n数之和。去重原理一样。
        ans.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0);
        return ans;
    }
};