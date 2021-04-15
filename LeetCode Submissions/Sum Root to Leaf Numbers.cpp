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
    void helper(TreeNode* root, int curr, int& ans, int count)
    {
        if(root==NULL)
            return;

        if(root->left==NULL && root->right==NULL)
        {
            curr=(curr*10)+root->val;
            ans+=curr;
            return;
        }

        if(count!=1)
            curr=(curr*10)+root->val;

        helper(root->left, curr, ans, count+1);
        helper(root->right, curr, ans, count+1);
    }

    int sumNumbers(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }

        int ans=0;
        helper(root, root->val, ans, 1);
        return ans;
    }
};
