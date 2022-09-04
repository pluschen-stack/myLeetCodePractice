#include"../defs.h"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(int i:nums1){
            for(int j:nums2){
                mp[i+j]++;
            }
        }
        int count = 0;
        for(int i:nums3){
            for(int j:nums4){
                if(mp.count(0-(i+j))){
                    count+=mp[0-(i+j)];
                }
            }
        }
        return count;
    }
};