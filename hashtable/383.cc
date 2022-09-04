#include"../defs.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26]={0};
        for(size_t i = 0; i < ransomNote.size();i++){
            record[ransomNote[i]- 'a']++;
        }
        for(size_t i = 0; i < magazine.size();i++){
            record[magazine[i]- 'a']--;
        }
        for(size_t i = 0;i < 26;i++){
            if(record[i]>0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    s.canConstruct("aa","baa");
}