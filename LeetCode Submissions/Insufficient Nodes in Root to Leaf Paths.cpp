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
    TreeNode* helper(TreeNode* root, int& limit, int curr)
    {
        if(root==NULL)
            return NULL;

        curr+=root->val;

        if(root->left==NULL && root->right==NULL)
        {
            if(curr<limit)
                return NULL;

            return root;
        }

        root->left=helper(root->left, limit, curr);
        root->right=helper(root->right, limit, curr);

        if(root->left==NULL && root->right==NULL)
            return NULL;

        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit)
    {
        root=helper(root, limit, 0);
        return root;
    }
};
