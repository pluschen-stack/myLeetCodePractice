#include"../defs.h"
#include"tree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return helper(root,height);
    }

    bool helper(TreeNode* cur,int & height){
        if(cur == nullptr) return true;
        int leftHeight = 0,rightHeight = 0;
        if(helper(cur->left,leftHeight)&&helper(cur->right,rightHeight)){
            if(abs(leftHeight-rightHeight)>1){
                height = max(leftHeight,rightHeight)+1;
                return false;
            }else{
                height = max(leftHeight,rightHeight)+1;
                return true;
            }
        }
        return false;
    }
};