#include "../defs.h"

class Solution
{
private:
    class MyComperation
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyComperation> pq;
        for(unordered_map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
            pq.push(*it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};