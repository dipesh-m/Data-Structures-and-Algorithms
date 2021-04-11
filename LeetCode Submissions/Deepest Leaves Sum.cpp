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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;

        return 1+max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root, int& ans, int height){
        if(root==NULL)
            return;

        if(height==1){
            ans+=root->val;
            return;
        }

        solve(root->left, ans, height-1);
        solve(root->right, ans, height-1);
    }

    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        int ans=0;

        solve(root, ans, h);
        return ans;
    }
};
