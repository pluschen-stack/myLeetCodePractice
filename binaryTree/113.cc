#include"../defs.h"
#include"tree.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> path;
        helper(root,targetSum,ans,path);
        return ans; 
    }

    void helper(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>& path){
        if(root->left==nullptr&&root->right==nullptr){
            if(root->val==targetSum){
                path.push_back(root->val); 
                ans.push_back(path);
                path.pop_back();
            }   
            return;
        }
        if(root->left!=nullptr){
            path.push_back(root->val);
            helper(root->left,targetSum-root->val,ans,path);
            path.pop_back();
        }
        if(root->right!=nullptr){
            path.push_back(root->val);
            helper(root->right,targetSum-root->val,ans,path);
            path.pop_back();
        }
        return;
    }
};