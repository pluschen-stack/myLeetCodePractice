#include"../defs.h"
#include"../binaryTree/tree.h"

class Solution {
private:
    unordered_map<TreeNode *,pair<int,int>> dp;
    void dfs(TreeNode * root){
        //插入节点
        dp[root].first = 0;
        dp[root].second = 0;
        if(root->left){
            dfs(root->left);
        }
        if(root->right){
            dfs(root->right);
        }
        //pair的first表示这个节点的房间要被偷
        dp[root].first = dp[root->left].second+dp[root->right].second+root->val;
        //pair的second表示这个节点的房间不会被偷
        dp[root].second = max(dp[root->left].first,dp[root->left].second)+max(dp[root->right].first,dp[root->right].second);
    }
public:
    int rob(TreeNode* root) {
        //树形DP，采用后序遍历的方式
        //初始化nullptr方便处理叶子节点
        dp[nullptr].first = 0;
        dp[nullptr].second = 0;
        dfs(root);
        return max(dp[root].first,dp[root].second);
    }
};