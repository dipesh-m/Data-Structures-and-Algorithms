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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        TreeNode* newNode=new TreeNode(val);
        TreeNode* curr=root;
        if(curr==NULL)
            return newNode;

        while(curr!=NULL)
        {
            if(val<curr->val)
            {
                if(curr->left==NULL)
                {
                    curr->left=newNode;
                    return root;
                }

                curr=curr->left;
            }
            else
            {
                if(curr->right==NULL)
                {
                    curr->right=newNode;
                    return root;
                }

                curr=curr->right;
            }
        }

        return root;
    }
};
