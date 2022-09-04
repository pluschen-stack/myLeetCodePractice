#include "../defs.h"
#include "tree.h"


class Solution {
private:
    TreeNode* freeTree(TreeNode* root){
        if(root == nullptr) return nullptr;
        root->left =freeTree(root->left);
        root->right = freeTree(root->right);
        delete root;
        return nullptr;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //这道题leetcode上释放节点会出现heap use after free的错误，不知道为什么
        if(root == nullptr) return nullptr;
        if(root->val < low){
            root->left = freeTree(root->left);
            TreeNode* temp = root->right;
            delete root;
            return trimBST(temp,low,high);
        }else if(root->val > high){
            root->right = freeTree(root->right);
            TreeNode* temp = root->left;
            delete root;
            return trimBST(temp,low,high);
        }
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1,nullptr,new TreeNode(2));
    TreeNode* temp = s.trimBST(root,2,4);
    cout << temp->val << endl;
}