#include"../defs.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t left = 0;
        size_t right = s.size()-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    Solution s;
    vector<char> a = {'1','2','3'};
    s.reverseString(a);
    
}