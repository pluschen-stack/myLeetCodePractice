#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left != nullptr)
                    que.push(temp->left);
                if (temp->right != nullptr)
                    que.push(temp->right);
            }
            ans++;
        }
        return ans;
    }
};