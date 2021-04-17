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
    int height(Node* root)
    {
        int maxHere=0;
        for(int i=0; i<root->children.size(); i++)
        {
            maxHere=max(maxHere, height(root->children.at(i)));
        }

        return 1+maxHere;
    }

    void helper(Node* root, int k, vector<vector<int>>& ans)
    {
        ans.at(k).push_back(root->val);

        for(int i=0; i<root->children.size(); i++)
        {
            helper(root->children.at(i), k+1, ans);
        }
    }

    vector<vector<int>> levelOrder(Node* root)
    {
        if(root==NULL)
        {
            vector<vector<int>> ans;
            return ans;
        }

        int h=height(root);
        vector<vector<int>> ans(h);
        helper(root, 0, ans);
        return ans;
    }
};
