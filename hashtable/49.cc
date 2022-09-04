#include"../defs.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> helper;
        vector<vector<string>> result;
        for(size_t i = 0; i<strs.size() ; i++){
            helper[consrtuctHash(strs[i])].emplace_back(strs[i]);
        }
        for (auto it = helper.begin(); it != helper.end(); ++it) {
            result.emplace_back(it->second);
        }

        return result;
    }

    //将字符串abbaac组织成a3b2c1的样子，方便hash
    string consrtuctHash(const string& str){
        size_t helper[26] = {0};
        for(size_t i = 0; i < str.size();i++){
            helper[str[i]-'a']++;
        }
        string result;
        for(size_t j = 0; j < 26; j++){
            result += (char)('a'+j)+helper[j];
        }
        return result;
    }
};