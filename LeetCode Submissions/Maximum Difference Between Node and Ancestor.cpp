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
    pair<int, int> helper(TreeNode* root, int& ans)
    {
        if(root==NULL)
        {
            pair<int, int> p;
            p.first=INT_MAX;
            p.second=INT_MIN;
            return p;
        }

        pair<int, int> leftOut=helper(root->left, ans);
        pair<int, int> rightOut=helper(root->right, ans);

        if(root->left!=NULL || root->right!=NULL)
        {
            if(leftOut.first!=INT_MAX && rightOut.first!=INT_MAX)
            {
                ans=max(ans, max(max(abs(root->val-leftOut.first), abs(root->val-leftOut.second)), max(abs(root->val-rightOut.first), abs(root->val-rightOut.second))));
            }
            else if(leftOut.first!=INT_MAX)
            {
                ans=max(ans, max(abs(root->val-leftOut.first), abs(root->val-leftOut.second)));
            }
            else
            {
                ans=max(ans, max(abs(root->val-rightOut.first), abs(root->val-rightOut.second)));
            }
        }

        pair<int, int> re;
        re.first=min(root->val, min(leftOut.first, rightOut.first));
        re.second=max(root->val, max(leftOut.second, rightOut.second));

        return re;
    }

    int maxAncestorDiff(TreeNode* root)
    {
        int ans=INT_MIN;
        pair<int, int> k=helper(root, ans);
        return ans;
    }
};
