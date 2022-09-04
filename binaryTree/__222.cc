#include"../defs.h"
#include"tree.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        //这个做法利用了完全二叉树的特性，它一定是由小的二叉树拼接成的
        if(root==nullptr) return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left!=nullptr){
            left = left->left;
            leftHeight++;
        }
        while(right!=nullptr){
            right = right->right;
            rightHeight++;
        }
        if(leftHeight==rightHeight){
            return (2<<leftHeight)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};