#include"../defs.h"
#include"tree.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if(root!=nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> row;
            for(int i = 0; i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                row.push_back(temp->val);
                if(temp->left!=nullptr) que.push(temp->left);
                if(temp->right!=nullptr) que.push(temp->right);
            }
            ans.push_back(row);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};