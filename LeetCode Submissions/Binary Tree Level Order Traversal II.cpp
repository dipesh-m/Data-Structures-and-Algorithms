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

    void helper(TreeNode* root, int k, vector<vector<int>>& ans, int h)
    {
        if(root==NULL)
            return;

        ans.at(h-k).push_back(root->val);

        helper(root->left, k+1, ans, h);
        helper(root->right, k+1, ans, h);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        int h=height(root);
        if(h==0)
        {
            vector<vector<int>> ans;
            return ans;
        }

        vector<vector<int>> ans(h);

        helper(root, 1, ans, h);
        return ans;
    }
};
