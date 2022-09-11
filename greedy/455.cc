#include"../defs.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sum = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ptrToG =0,ptrToS =0;
        while(ptrToS<s.size()&&ptrToG<g.size()){
            if(g[ptrToG]<=s[ptrToS]){
                //可以给ptrToG一个饼干
                sum++;
                ptrToG++;
                ptrToS++;
            }else{
                //给不了饼干
                ptrToS++;
            }
        }
        return sum;
    }
};