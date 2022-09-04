#include "../defs.h"

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        //深入理解题目后，可以知道next指针是一个可以利用的资源a
        //这里的处理是先解决右子树再解决左子树
        if (root == nullptr)
            return root;
        if (root->left != nullptr && root->right != nullptr)
        {
            if (root->next != nullptr)
            {
                root->right->next = root->next->left;
            }
            root->left->next = connect(root->right);
            connect(root->left);
        }
        return root;
    }

    Node *connectOld(Node *root)
    {
        queue<Node *> que;
        if (root != nullptr)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            Node *temp;
            Node *prev = nullptr;
            for (int i = 0; i < size; i++)
            {
                temp = que.front();
                que.pop();
                if (i != 0)
                {
                    prev->next = temp;
                }
                prev = temp;
                if (temp->left != nullptr)
                    que.push(temp->left);
                if (temp->right != nullptr)
                    que.push(temp->right);
            }
        }
        return root;
    }
};

int main()
{
    Solution s;
    Node *root;
    s.connect(root);
}