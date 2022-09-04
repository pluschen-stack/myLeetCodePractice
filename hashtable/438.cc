#include "../defs.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        size_t slow = -1, fast = p.size() - 1;
        int helper[26] = {0};
        for (size_t i = 0; i < p.size(); i++)
        {
            helper[p[i] - 'a']--;
            helper[s[i] - 'a']++;
        }
        while (fast < s.size()-1)
        {
            if(check(helper)){
                ans.push_back(slow+1);
            }
            helper[s[++fast] - 'a']++;
            helper[s[++slow] - 'a']--;
        }
        if(check(helper)){
            ans.push_back(slow+1);
        }
        return ans;
    }

    bool check(const int *helper)
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (helper[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    s.findAnagrams("baa","aa");
}