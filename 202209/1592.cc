#include"../defs.h"

class Solution {
public:
    string reorderSpaces(string text) {
        //注意心细，干！
        int whiteSpaceCount = 0;
        int wordCount = 0;
        for(int i = 0;i<text.size();i++){
            if(text[i]==' ') whiteSpaceCount++;
            else {
                wordCount++;
                for(;i<text.size()&&text[i]!=' ';i++);
                i--;
            }
        }
        int interval = wordCount==1?whiteSpaceCount:whiteSpaceCount/(wordCount-1);
        string ans;
        ans.resize(text.size());
        int slow = 0;
        int fast = 0;
        while(fast<text.size()){
            for(;fast<text.size()&&text[fast]==' ';fast++);
            for(;fast<text.size()&&text[fast]!=' ';fast++){
                ans[slow++]=text[fast];
            }
            for(int i = 0;i < interval&&slow<ans.size();i++){
                ans[slow++]=' ';
            }
        }
        for(;slow<ans.size();slow++){
            ans[slow]=' ';
        }
        return ans;
    }
};

int main(){
    Solution s;
    string text = "  this   is  a sentence ";
    s.reorderSpaces(text);
}