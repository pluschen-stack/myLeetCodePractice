#include"../defs.h"

class Solution {

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int prev=-1,res = 0;
        //学习一下了stl操作。
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        for(auto pair:pairs){
            if(prev<pair[0]){
                prev = pair[1];
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> a;
    a.push_back(vector<int>{2,3});
    a.push_back(vector<int>{3,2});
    a.push_back(vector<int>{1,2});
    s.findLongestChain(a);
}