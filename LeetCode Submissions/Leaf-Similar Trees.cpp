/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, vector<int>& v, int& i)
    {
        if(root==NULL)
            return true;

        if(root->left==NULL && root->right==NULL)
        {
            if(i==v.size() || v.at(i)!=root->val)
                return false;

            i++;
        }

        if(check(root->left, v, i)==false)
            return false;

        if(check(root->right, v, i)==false)
            return false;

        return true;
    }

    void helper(TreeNode* root, vector<int>& v)
    {
        if(root==NULL)
            return;

        if(root->left==NULL && root->right==NULL)
            v.push_back(root->val);

        helper(root->left, v);
        helper(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> first;
        helper(root1, first);
        int i=0;

        bool ans=check(root2, first, i);

        if(ans && i!=first.size())
            return false;

        return ans;
    }
};
