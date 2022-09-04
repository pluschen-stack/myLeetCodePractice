#include "../defs.h"
#include "tree.h"

class Solution {
private:
    TreeNode* prev = nullptr;
    int result = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        //这道题和98差不多，一样中序遍历然后比较绝对差就好了。同时大减小一定大于0，所以不用abs。
        if(root==nullptr) return 0;
        getMinimumDifference(root->left);
        if(prev!=nullptr) result = min(result,root->val-prev->val);
        prev = root;
        getMinimumDifference(root->right);
        return result;
    }
};