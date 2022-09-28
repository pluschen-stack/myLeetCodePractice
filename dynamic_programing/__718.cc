#include "../defs.h"

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2){
        //此题还有更快的解法。
        //O(m*n)解法，dp[i][j]表示以nums1的第i个数和nums2的第j个数结尾的最长公共数组长度
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1));
        int ans = 0;
        for(int i = 1; i <= nums1.size();i++){
            for(int j = 1; j <= nums2.size();j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(dp[i][j],ans);
                }
            }
        }
        return ans;
    }
    int findLengthBrute(vector<int> &nums1, vector<int> &nums2)
    {
        //O(m*n*min(m,n))的解法
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++)
        { 
            for (int l = 0; l < nums2.size();l++)
            {
                int temp = 0;
                for (int k = i, j = l; j < nums2.size() && k < nums1.size(); k++, j++)
                {
                    if (nums1[k] == nums2[j])
                    {
                        temp++;
                    }
                    else
                    {
                        ans = max(temp, ans);
                        temp = 0;
                    }
                }
                ans = max(temp, ans);
            }
        }
        return ans;
    }
};