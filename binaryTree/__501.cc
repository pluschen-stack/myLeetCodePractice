#include "../defs.h"
#include "tree.h"

class Solution
{
private:
    int count = 1;    //当前数的出现次数
    int maxCount = 1; //众数出现次数
    TreeNode *prev= nullptr;
public:
    vector<int> findMode(TreeNode *root)
    {
        //这道题我在怎样有序数组中求众数的地方卡了。。属实笨比了，想到map就忘了遍历两次了。当然这题可以只遍历一次
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        helper(root->left, ans);
        if (prev != nullptr)
        {
            if (prev->val == root->val)
            {
                count++;
            }
            else
            {
                count = 1;
            }
        }
        prev = root;
        if (count > maxCount)
        {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if (count == maxCount)
        {
            ans.push_back(root->val);
        }
        helper(root->right, ans);
    }
};

int main(){
    TreeNode* root = new TreeNode(1,nullptr,new TreeNode(2,new TreeNode(2),nullptr));
    Solution s;
    s.findMode(root);
}