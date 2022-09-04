#include "../defs.h"
#include "tree.h"


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size());
    }

    TreeNode* helper(vector<int>& nums,int low,int high){
        if(low==high) return nullptr;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left =  helper(nums,low,mid);
        root->right = helper(nums,mid+1,high);
        return root;
    }
};