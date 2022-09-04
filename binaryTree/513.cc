#include"../defs.h"
#include"tree.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int ans = root->val;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                if(i == 0){
                    ans = temp->val;
                }
                if(temp->left!=nullptr) que.push(temp->left);
                if(temp->right!=nullptr) que.push(temp->right);
            }
        }
        return ans;
    }
};