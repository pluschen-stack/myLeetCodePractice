#include "../defs.h"

class Solution
{
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {   
        //按照身高降序排序，身高相同的按k值增序排序
        if(a[0]==b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        //要我自己写肯定写不出来
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> ans;
        for(int i = 0; i < people.size();i++){
            int position = people[i][1];
            list<vector<int>>::iterator itr = ans.begin();
            advance(itr,position);
            ans.insert(itr,people[i]);
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

int main()
{
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution s;
    vector<vector<int>> ans = s.reconstructQueue(people);
    for(int i = 0;i < people.size();i++){
        printf("[%d %d] ",ans[i][0],ans[i][1]);
    }
}