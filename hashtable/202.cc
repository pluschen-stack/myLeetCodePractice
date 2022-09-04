#include"../defs.h"

class Solution {
public:
    bool isHappy(int n) {
        //n的第二次开始以后的数在int能表示的范围一定在3位数以内，所以根据鸽巢原理，不会出现无限不循环的情况
        unordered_set<int> nums_set;
        while(n!=1){
            if(nums_set.count(n)){
                return false;
            }
            nums_set.insert(n);
            n=helpHappy(n);
        }
        return true;
    }

    int helpHappy(int n){
        int sum = 0;
        while(n!=0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
};