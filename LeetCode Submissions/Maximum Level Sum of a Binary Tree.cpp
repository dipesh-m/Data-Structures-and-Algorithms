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
    int maxLevelSum(TreeNode* root)
    {
        int maximal=INT_MIN, ans, k=1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz=q.size();
            int curr=0;
            for(int i=0; i<sz; i++)
            {
                TreeNode* fr=q.front();
                q.pop();

                curr+=fr->val;

                if(fr->left)
                    q.push(fr->left);
                if(fr->right)
                    q.push(fr->right);
            }

            if(curr>maximal)
            {
                maximal=curr;
                ans=k;
            }

            k++;
        }

        return ans;
    }
};
