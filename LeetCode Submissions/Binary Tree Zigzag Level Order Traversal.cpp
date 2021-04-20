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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        return 1+max(height(root->left), height(root->right));
    }

    void helper(TreeNode* root, int k, vector<vector<int>>& ans, bool rev)
    {
        if(root==NULL)
            return;

        if(rev)
        {
            ans.at(k).insert(ans.at(k).begin(), root->val);
            rev=false;
        }
        else
        {
            ans.at(k).push_back(root->val);
            rev=true;
        }

        helper(root->left, k+1, ans, rev);
        helper(root->right, k+1, ans, rev);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans(height(root));
        if(root==NULL)
            return ans;

        helper(root, 0, ans, false);

        return ans;
    }
};
