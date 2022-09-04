#include"../defs.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        vector<int> ans;
        for(size_t i = 0;i < nums1.size();i++){
            if(!map.count(nums1[i])){
                map[nums1[i]] = false;
            }
        }
        for(size_t i = 0;i < nums2.size();i++){
            if(map.count(nums2[i])){
                map[nums2[i]] = true;
            }
        }
        for(auto element:map){
            if(element.second == true){
                ans.emplace_back(element.first);
            }
        }
        return ans;
    }
};