#include "../defs.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        //如果将去掉空格和翻转单词写在一起可以更快一些应该。懒得改了
        size_t fast = 0;
        size_t slow = 0;
        size_t length = s.size();
        //去掉多余的空格
        for (; fast < length; fast++)
        {
            if (s[fast] != ' ')
            {
                s[slow++] = s[fast];
            }
            else if (fast > 0 && s[fast - 1] != ' ')
            {
                s[slow++] = s[fast];
            }
        }
        if(s[length-1]==' '){
            s.resize(slow-1);
        }else{
            s.resize(slow);
        }
        //反转每一个单词
        for(size_t prev = 0,cur = 0;cur<s.size();cur++){
            if(s[cur]==' '){
                reverse(s.begin()+prev,s.begin()+cur);
                prev=cur+1;
            }else if(cur==s.size()-1){
                reverse(s.begin()+prev,s.end());
            }
        }
        //反转字符串
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl;
}