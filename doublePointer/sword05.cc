#include"../defs.h"

class Solution {
public:
    string replaceSpace(string s) {
        size_t whiteSpaceCount = 0;
        for(auto c:s){
            if(c == ' '){
                whiteSpaceCount++;
            }
        }
        int i = s.size()-1;
        s.resize(s.size()+whiteSpaceCount*2);
        for(int right = s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                s[right--]=s[i];
            }else{
                s[right]='0';
                s[right-1]='2';
                s[right-2]='%';
                right-=3;
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    s.replaceSpace("a b c ");
}