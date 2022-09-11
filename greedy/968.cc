#include"../defs.h"
#include"../binaryTree/tree.h"

class Solution {
private:
    int ans;
//0：没有被摄像头覆盖
//1：被摄像头覆盖
//2：有摄像头
    int helper(TreeNode *root){
        if(root==nullptr) return 1;//叶子节点应该是有被摄像头覆盖
        int left = helper(root->left);
        int right = helper(root->right);
        if(left == 0 || right == 0) {ans++;return 2;}
        if(left == 2 || right == 2) {return 1;}
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        ans = 0;
        if(helper(root)==0){
            ans++;
        };
        return ans;
    }
};

int main(){
    Solution s;
    s.minCameraCover(new TreeNode(0,new TreeNode(0,new TreeNode(0),new TreeNode(0)),nullptr));
}