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
    void helper(TreeNode* root, string temp, string& ans)
    {
        if(root==NULL)
            return;

        temp=(char)('a'+root->val)+temp;

        if(root->left==NULL && root->right==NULL)
        {
            if(ans=="")
                ans=temp;
            else
                ans=min(ans,temp);
        }

        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }

    string smallestFromLeaf(TreeNode* root)
    {
        string ans;
        helper(root, "", ans);
        return ans;
    }
};
