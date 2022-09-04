#include "../defs.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            size_t left = i+1;
            size_t right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]>0) right--;
                else if(nums[left]+nums[right]+nums[i]<0) left++;
                else{
                    result.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left < right && nums[right]==nums[right-1]) right--;
                    while(left < right && nums[left] == nums[left+1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }


    vector<vector<int>> threeSumOld(vector<int> &nums)
    {
        //在倒数第三个例子超时了。。
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_set<string> string_set;
        // 给倒数第三个写的，没想到全通过了也是超时，干
        // int zerocount=0;
        // for(int i:nums){
        //     if(i==0){
        //         zerocount++;
        //     }else{
        //         break;
        //     }
        // }
        // if(zerocount>20){
        //     return {{0,0,0}};
        // }
        for(int i = 0; i < nums.size();i++){
            if(nums[i]>0) break;
            unordered_set<int> int_set;
            for(int j = i+1; j < nums.size();j++){
                if (int_set.count(-nums[i] - nums[j]))
                {
                    string_set.insert(product(nums[i], nums[j], -nums[i] - nums[j]));
                }else{
                    int_set.insert(nums[j]);
                }
            }
        }
                
        for (string s : string_set)
        {
            ans.emplace_back(convert(s));
        }
        return ans;
    }

    string product(int low, int mid, int high)
    {
        if (low > mid)
            return product(mid, low, high);
        if (mid > high)
            return product(low, high, mid);
        return to_string(low) + ";" + to_string(mid) + ";" + to_string(high);
    }

    vector<int> convert(string s)
    {
        size_t last = 0;
        size_t next = 0;
        vector<int> result;
        while ((next = s.find(";", last)) != string::npos)
        {
            result.emplace_back(stoi(s.substr(last, next - last)));
            last = next + 1;
        }
        result.emplace_back(stoi(s.substr(last)));
        return result;
    }
};

int main(){
    
}