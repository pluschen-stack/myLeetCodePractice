#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if (root->right == nullptr)
            {
                //右子树是空的
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if( root->left == nullptr){
                //左子树是空的
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                //右子树不是空的,这里我的做法是教科书上一般写的交换节点的值然后去删，这样不太影响高度。
                //不过这个题可以直接把root的左子树放到右子树的最左节点的左子树上，然后删除root，返回root的右子树
                TreeNode *temp = root->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                root->val = temp->val;
                temp->val = key;
                //这里必须有这一步，否则虽然节点被释放了，但是还有指向它的指针没有被更新。
                root->right = deleteNode(root->right, key);   
            }
        }
        return root;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(5,new TreeNode(3,new TreeNode(2),new TreeNode(4)),new TreeNode(6,nullptr,new TreeNode(7)));
    s.deleteNode(root,3);
    cout << root->val << endl;
}