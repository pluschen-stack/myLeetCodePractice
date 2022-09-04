#include"../defs.h"
#include"tree.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //判断左叶子节点只能通过左叶子节点的父亲才行，这里也是后序遍历
        if(root==nullptr) return 0;
        else if(root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr){
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        else{
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        }
    }
};