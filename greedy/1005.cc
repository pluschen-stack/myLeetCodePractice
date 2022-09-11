#include "../defs.h"

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        //感觉自己在细节上的考量太差了，要注意细节啊。
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(k > 0){
                if(nums[i]<0){
                    sum += -nums[i];
                    k--;
                }else{
                    if(k%2==0){
                        k = 0;
                        sum += nums[i];
                    }else if(nums[i]==0){
                        k = 0;
                    }else{
                        if(i==0){
                            sum+=-nums[i];
                        }else if(-nums[i-1]>nums[i]){
                            sum += -nums[i];
                        }else{
                            sum += 2*nums[i-1]+nums[i];
                        }
                        
                        k = 0;
                    }
                }
            }else{
                sum += nums[i];
            }
        }
        if(k > 0){
            if(k%2==0) return sum;
            else{
                return sum+2*nums[nums.size()-1];
            }
        }
        return sum;
    }
};