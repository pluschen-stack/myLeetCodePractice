#include"../defs.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,size_t> map;
        vector<int> ans;
        for(size_t i = 0;i < nums1.size();i++){
            map[nums1[i]]++;
        }
        for(size_t i = 0;i < nums2.size();i++){
            if(map.count(nums2[i])&&map[nums2[i]]!=0){
                map[nums2[i]]--;
                ans.emplace_back(nums2[i]);
            }
        }
        return ans;
    }
};