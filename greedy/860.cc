#include "../defs.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5) return false;
        unordered_map<int,int> left;
        for(int i = 0;i<bills.size();i++){
            if(bills[i]==5){
                left[5]++;
            }else if(bills[i]==10){
                if(left[5]>=1){
                    left[5]--;
                    left[10]++;
                }else{
                    return false;
                }
            }else if(bills[i]==20){
                if(left[10]>=1&&left[5]>=1){
                    left[5]--;
                    left[10]--;
                }else if(left[5]>=3){
                    left[5]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};