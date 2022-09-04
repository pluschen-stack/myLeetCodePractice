#include"../defs.h"

class Solution {
public:
    string reverseStr(string s,int k){
        size_t length = s.size();
        size_t loop = s.size()/(2*k);
        size_t pos = 0;
        while(loop--){
            reverse(s.begin()+pos,s.begin()+pos+k);
            pos += 2*k;
        }
        if(length<pos+k){
            //剩下的长度小于k
            reverse(s.begin()+pos,s.end());
        }else{
            reverse(s.begin()+pos,s.begin()+pos+k);
        }
        return s;
    }


    string reverseStrOld(string s, int k) {
        size_t length = s.size();
        size_t loop = s.size()/(2*k);
        size_t pos = 0;
        while(loop--){
            size_t left = pos;
            size_t right = pos+k-1;
            while(left<right){
                swap(s[left++],s[right--]);
            }
            pos += 2*k;
        }
        if(length<pos+k){
            //剩下的长度小于k
            size_t left = pos;
            size_t right = length-1;
            while(left<right){
                swap(s[left++],s[right--]);
            }
        }else{
            size_t left = pos;
            size_t right = pos+k-1;
            while(left<right){
                swap(s[left++],s[right--]);
            }
            pos += 2*k;
        }
        return s;
    }
};

int main(){
    Solution s;
    s.reverseStr("abcdefg",2);
}