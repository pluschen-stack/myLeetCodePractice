#include "../defs.h"

class Solution
{
private:
    vector<string> ans;

    bool isLegal(string &s)
    {
        if (s.size() == 1)
        {
            return true;
        }
        else if ((s.size() == 2 || s.size() == 3) && (s[0] != '0'))
        {
            if(stoi(s)<=255){
                return true;
            }
            return false;
        }
        return false;
    }
    /**
     * @brief
     *
     * @param s
     * @param path
     * @param startIndex
     * @param count 还可以划分的次数
     */
    void backtracking(string &s, string path, int startIndex, int count)
    {
        if (count <= 0)
        {
            if (startIndex >= s.size())
            {
                ans.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            string substr = s.substr(startIndex, i - startIndex + 1);
            if (isLegal(substr))
            {
                if (count != 1)
                {
                    backtracking(s, path + substr + ".", i + 1, count - 1);
                }
                else
                {
                    backtracking(s, path + substr, i + 1, count - 1);
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        ans.clear();
        backtracking(s, "", 0, 4);
        return ans;
    }
};

int main()
{
}