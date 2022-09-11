#include "../defs.h"


class Solution {
private:
    int divideAndConquer(vector<int>& nums,int left,int right){
        if(left==right){
            //解决只有一个元素的区间
            return nums[left];
        }
        //接下来都是有两个以上的元素的区间，所以leftBorderSum+rightBorderSum除非数据本身会溢出，否则相加不会溢出。
        int mid = left+(right-left)/2;
        int leftSum = divideAndConquer(nums,left,mid);
        int rightSum = divideAndConquer(nums,mid+1,right);
        int leftBorderSum = INT_MIN;
        int rightBorderSum = INT_MIN;
        int temp = 0;
        for(int i = mid+1;i<=right;i++){
            temp += nums[i];
            rightBorderSum = max(rightBorderSum,temp);
        }
        temp = 0;
        for(int i = mid;i>=left;i--){
            temp+=nums[i];
            leftBorderSum = max(leftBorderSum,temp);
        }
        return max(max(leftBorderSum+rightBorderSum,leftSum),rightSum);
    }

public:
    int maxSubArray(vector<int>& nums) {
        // return divideAndConquer(nums,0,nums.size()-1);
        //这题的贪心法。渣男
        int count = 0;
        int result = INT_MIN;
        for(int& i:nums){
            count += i;
            if(count>result){
               result=count; 
            }
            if(count<0){
                count = 0;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> a = {-1,-2,-58,-788,-989};
    cout<<s.maxSubArray(a)<<endl;
}