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
    void helper(TreeNode* root, vector<string>& ans, string& im)
    {
        if(root==NULL)
            return;

        im+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
            ans.push_back(im);
        else
            im+="->";

        helper(root->left, ans, im);
        helper(root->right, ans, im);

        if(root->left!=NULL || root->right!=NULL)
            im.pop_back();

        int i=im.size()-1;
        while(i>=0 && im.at(i--)!='>')
            im.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        string im="";
        helper(root, ans, im);
        return ans;
    }
};
