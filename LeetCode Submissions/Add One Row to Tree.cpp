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
    void helper(TreeNode* root, int& val, int& depth, int k)
    {
        if(root==NULL)
            return;

        if(k==depth-1)
        {
            TreeNode* lst=root->left;
            TreeNode* rst=root->right;

            TreeNode* leftNewNode=new TreeNode(val);
            TreeNode* rightNewNode=new TreeNode(val);

            root->left=leftNewNode;
            leftNewNode->left=lst;

            root->right=rightNewNode;
            rightNewNode->right=rst;
        }

        helper(root->left, val, depth, k+1);
        helper(root->right, val, depth, k+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }

        helper(root, val, depth, 1);
        return root;
    }
};
