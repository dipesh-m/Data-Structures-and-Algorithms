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
    void depth(TreeNode* root, int& dep, int k)
    {
        if(root==NULL)
            return;

        dep=max(dep, k);

        depth(root->left, dep, k+1);
        depth(root->right, dep, k+1);
    }

    void helper(TreeNode* root, bool& nullFound, bool& ans, int& dep, int k)
    {
        if(root==NULL)
            return;

        if(k==dep-1)
        {
            if(root->left==NULL && root->right!=NULL)
            {
                ans=false;
                return;
            }

            if(nullFound==false && root->right==NULL)
            {
                nullFound=true;
            }
            else if(nullFound && (root->left!=NULL || root->right!=NULL))
            {
                ans=false;
                return;
            }
        }
        else if(k<dep-1)
        {
            if(root->left==NULL || root->right==NULL)
            {
                ans=false;
                return;
            }
        }

        helper(root->left, nullFound, ans, dep, k+1);
        helper(root->right, nullFound, ans, dep, k+1);
    }

    bool isCompleteTree(TreeNode* root)
    {
        bool ans=true;
        bool nullFound=false;

        int dep=INT_MIN;
        depth(root, dep, 0);

        helper(root, nullFound, ans, dep, 0);
        return ans;
    }
};
