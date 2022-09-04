#include"../defs.h"
#include"tree.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preorderBegin,int preorderEnd,vector<int>& inorder,int inorderBegin,int inorderEnd){
        if(preorderEnd==preorderBegin) return nullptr;//这说明大小为0
        TreeNode* root = new TreeNode(preorder[preorderBegin]);
        for(int i = inorderBegin;i<inorderEnd;i++){
            if(preorder[preorderBegin]==inorder[i]){
                //在中序数组中找到根的位置
                //中序数组中左子树的大小是i-inorderBegin
                root->left = buildTreeHelper(preorder,preorderBegin+1,preorderBegin+1+i-inorderBegin
                    ,inorder,inorderBegin,i);
                root->right = buildTreeHelper(preorder,preorderBegin+1+i-inorderBegin,preorderEnd,
                    inorder,i+1,inorderEnd);
                break;
            }
        } 
        return root;
    }
};