#include"../defs.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t record[26]={0};
        for(size_t i = 0; i < s.size();i++){
            record[s[i]- 'a']++;
        }
        for(size_t i = 0; i < t.size();i++){
            record[t[i]- 'a']--;
        }
        for(size_t i = 0;i < 26;i++){
            if(record[i]!=0){
                return false;
            }
        }
        return true;
    }
};