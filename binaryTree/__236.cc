#include "../defs.h"
#include "tree.h"

class Solution {
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        //使用后序遍历的方式结题，返回nullptr代表着没有找到结果，返回p代表着这颗子树里面有p，返回q代表着这棵子树里有q
        //只要子树里的结果不为空，那么就把它往上传。
        //这里我觉得代码随想录的比较精简，不过优化了很多。因为它分了两种情况的处理。
        if(root == nullptr) return nullptr;
        TreeNode* left = helper(root->left,p,q);
        TreeNode* right = helper(root->right,p,q);
        if(left==p&&right==q||left==q&&right==p){
            //这意味着左右两颗子树里有p或q，因此root就是答案，让他上传
            return root;
        }
        if(left==p||right==p){
            //这意味着左右两棵树里至少有一个p，往上传
            if(root==q){
                //这个情况是q包含p的情况。
                return root;
            }
            return p;
        }
        if(left==q||right==q){
            //这意味着左右两棵树里至少有一个q，往上传
            if(root == p){
                //这个情况是p包含q的情况。
                return root;
            }
            return q;
        }
        if(left!=nullptr){
            return left;
        }
        if(right!=nullptr){
            return right;
        }
        if(root==p||root==q){
            //这个是在左右子树没包含任何一个节点的情况，但是自己是p或q
            return root;
        }
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};