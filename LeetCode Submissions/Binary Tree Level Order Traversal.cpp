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
    unordered_set<int> us;
    vector<vector<int>> ans;

    void helper(TreeNode* root, int k)
    {
        if(root==NULL)
            return;

        if(us.count(k)==0)
        {
            us.insert(k);

            vector<int> im;
            im.push_back(root->val);
            ans.push_back(im);
        }
        else
        {
            ans.at(k).push_back(root->val);
        }

        helper(root->left, k+1);
        helper(root->right, k+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(root==NULL)
            return ans;

        helper(root, 0);
        return ans;
    }
};
