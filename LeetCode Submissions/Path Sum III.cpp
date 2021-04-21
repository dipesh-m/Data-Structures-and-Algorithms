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
    void helper(TreeNode* root, int currSum, int& targetSum, int& ans)
    {
        if(root==NULL)
            return;

        currSum+=root->val;
        if(currSum==targetSum)
            ans++;

        helper(root->left, currSum, targetSum, ans);
        helper(root->right, currSum, targetSum, ans);
    }

    void solve(TreeNode* root, int& targetSum, int& ans)
    {
        if(root==NULL)
            return;

        helper(root, 0, targetSum, ans);

        solve(root->left, targetSum, ans);
        solve(root->right, targetSum, ans);
    }

    int pathSum(TreeNode* root, int& targetSum)
    {
        if(root==NULL)
            return 0;

        int ans=0;
        solve(root, targetSum, ans);

        return ans;
    }
};
