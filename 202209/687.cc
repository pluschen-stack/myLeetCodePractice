#include"../binaryTree/tree.h"
#include"../defs.h"

class Solution {
private:
    int maxLength = 0;
    int helper(TreeNode* root){
        if(root == nullptr) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        if(root->left!=nullptr&&root->right!=nullptr&&root->left->val==root->val&&root->right->val==root->val){
            left++;
            right++;
            maxLength = max(left+right,maxLength);
            return max(left,right);
        }
        if(root->left!=nullptr&&root->left->val==root->val){
            left++;
            maxLength = max(left,maxLength);
        }else{
            left=0;
        }
        if(root->right!=nullptr&&root->right->val==root->val){
            right++;
            maxLength = max(right,maxLength);
        }else{
            right=0;
        }
        
        return max(left,right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        //官解的答案比我的简练很多，但思路是一样的，单独的一条边靠helper的返回值，两条边靠全局变量maxLength
        helper(root);
        return maxLength;
    }
};