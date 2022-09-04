#include "../defs.h"
#include "tree.h"

class Solution
{
public:
    TreeNode *buildTreeMine(vector<int> &inorder, vector<int> &postorder)
    {
        //因为反复创建vector比较超时，所以我这里直接复制了一下代码随想录里面的用索引的方法，本质都一样，还有就是可以用迭代器复制。
        if (postorder.size() == 0)
            return nullptr;
        int size = postorder.size();
        TreeNode *root = nullptr;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == postorder[size - 1])
            {
                //找到根节点
                root = new TreeNode(inorder[i]);
                vector<int> newInorder{&inorder[0], &inorder[0] + i};
                vector<int> newPostorder{&postorder[0], &postorder[0] + i};
                root->left = buildTreeMine(newInorder, newPostorder);
                vector<int> newInorder2{&inorder[0] + i + 1, &inorder[0] + size};
                vector<int> newPostorder2{&postorder[0] + i, &postorder[0] + size - 1};
                root->right = buildTreeMine(newInorder2, newPostorder2);
                break;
            }
        }

        return root;
    }

private:
    // 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
    TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd)
    {
        if (postorderBegin == postorderEnd)
            return NULL;

        int rootValue = postorder[postorderEnd - 1];
        TreeNode *root = new TreeNode(rootValue);

        if (postorderEnd - postorderBegin == 1)
            return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }
        // 切割中序数组
        // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割后序数组
        // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
        // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        // 左闭右开的原则
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
