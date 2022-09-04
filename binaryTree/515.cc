#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            int maxNum = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                maxNum = maxNum>cur->val?maxNum:cur->val;
                if(cur->left!=nullptr) que.push(cur->left);
                if(cur->right!=nullptr) que.push(cur->right);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};