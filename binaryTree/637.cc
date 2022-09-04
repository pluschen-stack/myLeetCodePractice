#include"../defs.h"
#include"tree.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> que;
        if(root!=nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            double rowAverage = 0;
            for(int i = 0; i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                rowAverage+=temp->val;
                if(temp->left!=nullptr) que.push(temp->left);
                if(temp->right!=nullptr) que.push(temp->right);
            }
            ans.push_back(rowAverage/size);
        }
        return ans;
    }
};