#include "../defs.h"
#include "tree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //和236比较起来，用中间节点的值减少遍历
        //看了一下代码随想录，直接通过区间确定就行。hh这样写的回溯还复杂了。
        if(root==p||root==q||root==nullptr) return root;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if(root->val>p->val&&root->val>q->val){
            left = lowestCommonAncestor(root->left,p,q);
        }else if(root->val<p->val&&root->val<q->val){
            right = lowestCommonAncestor(root->right,p,q);
        }else{
            left = lowestCommonAncestor(root->left,p,q);
            right = lowestCommonAncestor(root->right,p,q);
        }
        if(left != nullptr&&right!=nullptr) return root;
        if(left != nullptr) return left;
        else return right;
    }
};