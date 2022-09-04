#include "../defs.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *cur = st.top();
        while (cur->left != nullptr)
        {
            cur = cur->left;
            st.push(cur);
        }
        while (!st.empty())
        {
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            if (cur->right != nullptr){
                cur = cur->right;
                st.push(cur);
                while(cur->left!=nullptr){
                    cur = cur->left;
                    st.push(cur);
                }   
            }
        }
        return ans;
    }
};