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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz=q.size();
            int currMax=INT_MIN;
            for(int i=0; i<sz; i++)
            {
                TreeNode* fr=q.front();
                q.pop();

                currMax=max(currMax, fr->val);

                if(fr->left!=NULL)
                    q.push(fr->left);
                if(fr->right!=NULL)
                    q.push(fr->right);
            }

            ans.push_back(currMax);
        }

        return ans;
    }
};
