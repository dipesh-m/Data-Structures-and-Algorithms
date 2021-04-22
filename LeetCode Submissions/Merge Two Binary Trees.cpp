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
    TreeNode* addSecond(TreeNode* root, TreeNode* ans)
    {
        if(root==NULL)
            return ans;

        if(ans==NULL)
            return root;

        ans->val=ans->val+root->val;

        ans->left=addSecond(root->left, ans->left);
        ans->right=addSecond(root->right, ans->right);

        return ans;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
            return NULL;

        if(root1==NULL)
            return root2;

        if(root2==NULL)
            return root1;

        root1=addSecond(root2, root1);

        return root1;
    }
};
