#include"../defs.h"
#include"tree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        if(root->left==nullptr&&root->right==nullptr){
            if(root->val==targetSum) return true;
            else return false;
        }
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
};