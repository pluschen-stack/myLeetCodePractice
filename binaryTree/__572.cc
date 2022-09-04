#include "../defs.h"
#include "tree.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        //O(|root|*|subroot|)，力扣题解上有很多优秀的解法，可以学习一下
        if(isSubtreeHelper(root,subRoot)){
            return true;
        }else{
            if(root!=nullptr){
                return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
            }
                return false;
        }
    }

    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&&subRoot!=nullptr) return false;
        if(subRoot==nullptr&&root!=nullptr) return false;
        if(subRoot==nullptr&&root==nullptr) return true;
        if(subRoot->val!=root->val) return false;
        return isSubtreeHelper(root->left,subRoot->left)&&isSubtreeHelper(root->right,subRoot->right); 
    }
};