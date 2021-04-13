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
    int ans=INT_MIN;
    unordered_set<int> us;

    void helper(TreeNode* root, int k)
    {
        if(root==NULL)
            return;

        if(k>0 && us.count(k)==0)
        {
            us.insert(k);
            ans=root->val;
        }

        helper(root->left, k+1);
        helper(root->right, k+1);
    }

    int findBottomLeftValue(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
            return root->val;

        helper(root, 0);
        return ans;
    }
};
