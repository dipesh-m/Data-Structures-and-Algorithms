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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;

        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, 1));

        while(!st.empty())
        {
            if(st.top().second==1)
            {
                st.top().second++;
                if(st.top().first->left!=NULL)
                    st.push(make_pair(st.top().first->left, 1));
            }
            else if(st.top().second==2)
            {
                ans.push_back(st.top().first->val);

                st.top().second++;
                if(st.top().first->right!=NULL)
                    st.push(make_pair(st.top().first->right, 1));
            }
            else
            {
                st.pop();
            }
        }

        return ans;
    }
};
