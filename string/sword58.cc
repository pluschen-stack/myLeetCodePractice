#include"../defs.h"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //参考sword05
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};