#include"../defs.h"
#include"tree.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeHelper(nums,0,nums.size());
    }

private:
    TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums,int begin,int end){
        //O(n^2)的解法，原理同中序前序构造和中序后序构造相同，还有一个利用单调栈的O(n)方法，可以学习一下。
        if(begin==end) return nullptr;
        int pos = begin;
        int max = nums[begin];
        for(int i = begin;i<end;i++){
            if(nums[i]>max){
                max = nums[i];
                pos = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = constructMaximumBinaryTreeHelper(nums,begin,pos);
        root->right = constructMaximumBinaryTreeHelper(nums,pos+1,end);
        return root;
    }
};