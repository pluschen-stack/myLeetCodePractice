#include "../defs.h"
#include "tree.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //我看了一下代码随想录的代码，它新建节点的那个方法存在错误，会导致新建的节点的一部分还用到原来的树的一部分
        //修改方法就是加一个复制树的方法就可以了。
        if(root1==nullptr&&root2==nullptr) return nullptr;
        if(root1!=nullptr&&root2==nullptr) return root1;
        if(root2!=nullptr&&root1==nullptr) return root2;
        root1->val = root1->val+root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
};