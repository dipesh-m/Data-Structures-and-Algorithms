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
    int deepestLeavesSum(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        int ans=0;
        while(!q.empty())
        {
            ans=0;
            int sz=q.size();
            for(int i=0; i<sz; i++)
            {
                TreeNode* fr=q.front();
                q.pop();

                ans+=fr->val;

                if(fr->left)
                    q.push(fr->left);

                if(fr->right)
                    q.push(fr->right);
            }
        }

        return ans;
    }
};
