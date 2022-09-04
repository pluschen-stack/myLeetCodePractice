#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        //中序遍历就是从小到大的访问，这里使用long的原因是因为root节点的最小值是INT_MIN因此为了设置的比它小所以使用long
        //代码随想录给了一个更好的方法就是不用单独弄一个long来记录大小，直接记录前一个节点，我觉得很不错
        long prev = LONG_LONG_MIN;
        return helper(root, prev);
    }

    bool helper(TreeNode *root, long &prev)
    {
        if (root == nullptr)
            return true;
        if (!helper(root->left, prev))
        {   
            return false;
        }
        if(prev<root->val){
            prev = root->val;
        }else{
            return false;
        }
        if (!helper(root->right, prev))
        {
            return false;
        }
        return true;
    }

    bool isValidBSTFalse(TreeNode *root)
    {
        //这个是错误的，因为这里只比较了局部三个节点的情况。所以可能右子树里面最左边的节点可以比中间节点大。
        if (root->left == nullptr && root->right == nullptr)
            return true;
        else if (root->left != nullptr && root->right == nullptr)
        {
            if (root->left->val >= root->val)
                return false;
            else
                return isValidBSTFalse(root->left);
        }
        else if (root->right != nullptr && root->left == nullptr)
        {
            if (root->right->val <= root->val)
                return false;
            else
                return isValidBSTFalse(root->right);
        }
        else
        {
            if (root->left->val >= root->val)
                return false;
            if (root->right->val <= root->val)
                return false;
            return isValidBSTFalse(root->left) && isValidBSTFalse(root->right);
        }
    }
};