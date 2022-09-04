#include"../defs.h"
#include"tree.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        //后序遍历做法
        vector<string> ans;
        if(root == nullptr){}
        else if(root->left==nullptr&&root->right==nullptr){
            //是叶子节点
            ans.push_back(to_string(root->val));
        }
        else{
            //分别处理左右儿子的路径（也可以先把左右儿子的路径都拿到在处理，那样逻辑更符合后序遍历一点，这是简写的）
            for(string a:binaryTreePaths(root->left)){
                ans.push_back(to_string(root->val)+"->"+a);
            }
            for(string b:binaryTreePaths(root->right)){
                ans.push_back(to_string(root->val)+"->"+b);
            }
        }
        return ans;
    }
};