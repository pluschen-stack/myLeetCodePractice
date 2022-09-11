#include "../defs.h"

class Solution {
public:
    int canCompleteCircuitMine(vector<int>& gas, vector<int>& cost) {
        //感觉写的还不如暴力方法。干
        int sum = 0;
        int pos =0;
        int n = gas.size();
        for(int i = 0;i<n;i++){
            sum+=gas[i]-cost[i];
        }
        if(sum<0) return -1;
        sum = gas[0]-cost[0];
        int j = 1;
        while(true){
            if(j%n == pos){
                break;
            }
            if(sum < 0){
                //如果前面的sum小于0，说明他们走不到这里。
                sum = 0;
                pos = j%n;
            }
            sum += gas[j%n]-cost[(j++)%n];

        }
        return pos;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int pos = 0;
        for(int i = 0;i<gas.size();i++){
            totalSum+=gas[i]-cost[i];
            curSum+=gas[i]-cost[i];
            if(curSum<0){
                pos = i+1;
                curSum =0;
            }
        }
        return totalSum<0?-1:pos;
    }
};