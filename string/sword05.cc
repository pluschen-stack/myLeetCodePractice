#include "../defs.h"

class Solution {
public:
    string replaceSpace(string s) {
        size_t whiteSpaceCount = 0;
        for(char c:s){
            if(c==' '){
                whiteSpaceCount++;
            }
        }
        int left = s.size()-1;
        s.resize(s.size()+2*whiteSpaceCount);
        int right = s.size()-1;
        for(;left<right;left--){
            if(s[left]==' '){
                s[right] = '0';
                s[right-1] = '2';
                s[right-2] = '%';
                right-=3;
                continue;
            }
            s[right] = s[left];
            right--;
        }
        return s;
    }
};