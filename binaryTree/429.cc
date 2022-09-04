#include"../defs.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        queue<Node*> que;
        if(root!=nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> row;
            for(int i = 0; i < size;i++){
                Node* temp = que.front();
                que.pop();
                row.push_back(temp->val);
                for(int j = 0;j<temp->children.size();j++){
                    que.push(temp->children[j]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};