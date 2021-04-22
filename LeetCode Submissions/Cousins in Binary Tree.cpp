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
    TreeNode* parent(TreeNode* root, int& targ)
    {
        if(root==NULL)
            return NULL;

        if((root->left!=NULL && root->left->val==targ) || (root->right!=NULL && root->right->val==targ))
            return root;

        TreeNode* ans=NULL;
        ans=parent(root->left, targ);
        if(ans!=NULL)
            return ans;
        ans=parent(root->right, targ);
        if(ans!=NULL)
            return ans;

        return ans;
    }

    void depth(TreeNode* root, int& targ, int k, int& d)
    {
        if(root==NULL)
            return;

        if(root->val==targ)
        {
            d=k;
            return;
        }

        depth(root->left, targ, k+1, d);
        depth(root->right, targ, k+1, d);
    }

    bool isCousins(TreeNode* root, int x, int y)
    {
        int d1, d2;
        TreeNode* p1=root;
        TreeNode* p2=root;

        depth(root, x, 0, d1);
        depth(root, y, 0, d2);

        if(d1!=d2)
            return false;

        p1=parent(root, x);
        p2=parent(root, y);

        if(p1->val==p2->val)
            return false;

        return true;
    }
};
