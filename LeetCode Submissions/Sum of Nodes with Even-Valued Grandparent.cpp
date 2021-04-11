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
    int sumEvenGrandparent(TreeNode* root)
    {
        if(root==NULL)
            return 0;

        int ans=0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* _front=q.front();
            q.pop();

            if(_front->val%2==0)
            {
                if(_front->left!=NULL)
                {
                    if(_front->left->left!=NULL)
                        ans+=_front->left->left->val;
                    if(_front->left->right!=NULL)
                        ans+=_front->left->right->val;
                }
                if(_front->right!=NULL)
                {
                    if(_front->right->left!=NULL)
                        ans+=_front->right->left->val;
                    if(_front->right->right!=NULL)
                        ans+=_front->right->right->val;
                }
            }

            if(_front->left!=NULL)
                q.push(_front->left);
            if(_front->right!=NULL)
                q.push(_front->right);
        }

        return ans;
    }
};
