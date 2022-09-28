#include"../defs.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //感觉这题代码随想录的代码复杂了。这题的记忆化回溯算法算是一个不错的思路。
        //这题本质就是多重背包或者说爬楼梯
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1; i <= s.size();i++){
            for(const string& word:wordDict){
                if(i < word.size()) continue;
                //找了半天找到了这个函数用来比较后半部分
                if((s.find(word,i-word.size()) == i-word.size())&&dp[i-word.size()]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution s;
    vector<string> wordDict{"leet","code"};
    string ss = "leetcode";
    cout << s.wordBreak(ss,wordDict);
}

