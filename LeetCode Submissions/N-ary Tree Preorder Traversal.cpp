/*
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
*/

class Solution {
public:
    vector<int> ans;

    void helper(Node* root)
    {
        ans.push_back(root->val);
        for(int i=0; i<root->children.size(); i++)
        {
            helper(root->children.at(i));
        }
    }

    vector<int> preorder(Node* root)
    {
        if(root==NULL)
            return ans;

        helper(root);
        return ans;
    }
};
