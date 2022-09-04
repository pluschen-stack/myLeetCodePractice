#include "../defs.h"
#include "tree.h"

class Solution
{
private:
    TreeNode *prev = nullptr;

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        //逆中序遍历的话就是从大到小，就这样累加就可以了。
        if (root == nullptr)
            return nullptr;
        bstToGst(root->right);
        if (prev != nullptr)
        {
            root->val = root->val + prev->val;
        }
        prev = root;
        bstToGst(root->left);
        return root;
    }
};