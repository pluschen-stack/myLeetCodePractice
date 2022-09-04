#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // dfs方法
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right != nullptr)
        {
            return 1 + minDepth(root->right);
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    int minDepthOld(TreeNode *root)
    {
        // bfs方法
        int ans = 0;
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);
        bool Find = false;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left == nullptr && temp->right == nullptr)
                {
                    Find = true;
                    break;
                }
                if (temp->left != nullptr)
                    que.push(temp->left);
                if (temp->right != nullptr)
                    que.push(temp->right);
            }
            ans++;
            if (Find)
            {
                break;
            }
        }
        return ans;
    }
};