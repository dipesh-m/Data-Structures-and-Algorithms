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
    vector<TreeNode*> helper(TreeNode* root, TreeNode* target)
    {
        if(root==NULL)
        {
            vector<TreeNode*> empty;
            return empty;
        }

        if(root==target)
        {
            vector<TreeNode*> ans;
            ans.push_back(root);
            return ans;
        }

        vector<TreeNode*> leftOut=helper(root->left, target);
        if(leftOut.size()!=0)
        {
            leftOut.push_back(root);
            return leftOut;
        }
        else
        {
            vector<TreeNode*> rightOut=helper(root->right, target);
            if(rightOut.size()!=0)
            {
                rightOut.push_back(root);
                return rightOut;
            }
        }

        vector<TreeNode*> empty;
        return empty;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> first=helper(root, p);
        vector<TreeNode*> second=helper(root, q);

        int diff=first.size()-second.size();
        if(diff<0)
            diff=-diff;

        int i=0, j=0;
        if(first.size()>=second.size())
            i=diff;
        else
            j=diff;

        while(first.at(i)!=second.at(j))
        {
            i++;
            j++;
        }

        return first.at(i);
    }
};
