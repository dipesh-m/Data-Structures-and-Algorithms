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
    void helper(TreeNode* root, int k, vector<int>& v)
    {
        if(root==NULL)
            return;

        if(v.at(k)!=INT_MIN)
        {
            v.at(k)+=root->val;
        }
        else
        {
            v.at(k)=root->val;
        }

        helper(root->left, k+1, v);
        helper(root->right, k+1, v);
    }

    int maxLevelSum(TreeNode* root)
    {
        vector<int> v(10001, INT_MIN);
        helper(root, 1, v);

        return (max_element(v.begin(), v.end())-v.begin());
    }
};
