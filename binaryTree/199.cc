#include"../defs.h"
#include"tree.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if(root!=nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            TreeNode* temp;
            for(int i = 0; i < size;i++){
                temp = que.front();
                que.pop();
                if(temp->left!=nullptr) que.push(temp->left);
                if(temp->right!=nullptr) que.push(temp->right);
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};