#include "../defs.h"
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        queue<Node *> que;
        if (root != nullptr)
            que.push(root);
        int ans = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node *cur = que.front();
                que.pop();
                for(int i =0;i<cur->children.size();i++){
                    que.push(cur->children[i]);
                }
            }
            ans++;
        }
        return ans;
    }
};