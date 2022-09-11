#include "../defs.h"

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;
        unordered_map<char, int> uMap;
        for (int i = 0; i < s.size(); i++)
        {
            uMap[s[i]] = i;
        }
        int right = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, uMap[s[i]]);
            if (i == right)
            {
                ans.emplace_back(right - left + 1);
                left = i + 1;
            }
        }
        return ans;
    }
    vector<int> partitionLabelsOld(string s)
    {
        //看了标准解法，最远位置可以直接用map标记出来。效率比我这个好很多
        //我这是目光短浅的解法，找到了大致区间再去扩大它
        vector<int> ans;
        unordered_set<char> uSet;
        int left = 0;
        int right = s.size() - 1;
        int hasBeenSlicedNum = 0;
        int length = 1;
        uSet.insert(s[0]);
        while (hasBeenSlicedNum != s.size())
        {
            for (; right > left && uSet.find(s[right]) == uSet.end(); right--)
                ;
            if (left == right)
            {
                //在后半段没有找到之前出现过的元素
                ans.push_back(length);
                hasBeenSlicedNum += length;
                length = 1;
                left++;
                uSet.insert(s[left]);
            }
            else
            {
                // uSet.find(s[right]) != uSet.end()
                for (int i = left; i < right; i++)
                {
                    if (uSet.find(s[i]) == uSet.end())
                    {
                        uSet.insert(s[i]);
                    }
                }
                length += right - left;
                left = right;
            }
            right = s.size() - 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");
}