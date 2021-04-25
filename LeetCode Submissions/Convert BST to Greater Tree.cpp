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
    int helper(TreeNode* root, int leftCase)
    {
        if(root==NULL)
            return 0;

        int rstSum=helper(root->right, leftCase);

        if(leftCase!=0 && root->right==NULL)
            root->val=root->val+rstSum+leftCase;
        else
            root->val=root->val+rstSum;

        if(root->left!=NULL)
            return helper(root->left, root->val);

        return root->val;
    }

    TreeNode* convertBST(TreeNode* root)
    {
        int k=helper(root, 0);
        return root;
    }
};
