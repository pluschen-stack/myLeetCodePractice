#include "../defs.h"
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> mp;
        int letterCount = 0;
        convertToMap(t, mp, letterCount);
        size_t left = 0, right = 0;
        size_t realLeft = 0, realRight = s.size();
        bool isFind = false;
        for (; right < s.size(); right++)
        {
            if (mp.count(s[right]))
            {
                mp[s[right]]--;
                if (check(mp))
                {
                    while (true)
                    {
                        isFind = true;
                        if (right - left < realRight - realLeft)
                        {
                            realLeft = left;
                            realRight = right;
                        }
                        if (mp.count(s[left]))
                        {
                            mp[s[left]]++;
                            if (mp[s[left]] > 0)
                            {
                                left++;
                                break;
                            }
                        }
                        left++;
                    }
                }
            }
        }
        return isFind ? s.substr(realLeft, realRight-realLeft+1) : "";
    }
    void convertToMap(const string &t, unordered_map<char, int> &mp, int &letterCount)
    {
        for (size_t i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
    }
    bool check(const unordered_map<char, int> &mp)
    {
        for (const pair<char, int> &kv : mp)
        {
            if (kv.second > 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.minWindow("abc", "b") << endl;

    string s = "hello";
    cout << s.substr(0,1) << endl;
}