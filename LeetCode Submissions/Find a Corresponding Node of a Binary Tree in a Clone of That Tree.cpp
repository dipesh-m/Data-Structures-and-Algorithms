/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned==NULL)
            return NULL;

        if(cloned->val==target->val)
        {
            return cloned;
        }

        TreeNode* a=getTargetCopy(original, cloned->left, target);
        TreeNode* b=NULL;
        if(a==NULL)
        {
            b=getTargetCopy(original, cloned->right, target);
        }
        else
        {
            return a;
        }

        return b;
    }
};
