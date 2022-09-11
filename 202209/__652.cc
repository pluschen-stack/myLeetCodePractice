#include "../binaryTree/tree.h"
#include "../defs.h"

class Solution
{
private:
    unordered_map<string,TreeNode*> umap;
    unordered_set<TreeNode *> result;
    string dfs(TreeNode *root){
        if(root==nullptr){
            return "";
        }
        string serial = to_string(root->val)+"("+dfs(root->left)+")("+dfs(root->right)+")";
        auto it = umap.find(serial);
        if(it != umap.end()){
            //这里的result不能换成vector。因为可能会有多个子树的序列号相同，如果用vector就会加入很多重复的。
            //同时这里插入的是it->second而不是root的原因也是为了去重，否则会添加多个重复的结构（虽然他们不是同一个指针）。
            result.insert(it->second);
        }else{
            umap[serial] = root;
        }
        return serial;
    }
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        //这道题引进了使用序列化来解决相等的问题。感觉还挺巧妙的。
        dfs(root);
        return {result.begin(),result.end()};
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(4)),new TreeNode(3,new TreeNode(5,new TreeNode(6),nullptr),new TreeNode(6,nullptr,nullptr)));
    s.findDuplicateSubtrees(root);
}