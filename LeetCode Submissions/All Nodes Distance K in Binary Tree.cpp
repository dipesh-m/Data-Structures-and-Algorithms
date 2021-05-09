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
    void getUpwards(TreeNode* root, TreeNode* child, int k, int& K, vector<int>& ans)
    {
        if(root==NULL)
            return;

        if(k==K)
            ans.push_back(root->val);

        if(root->left==child)
            getUpwards(root->right, child, k+1, K, ans);
        else if(root->right==child)
            getUpwards(root->left, child, k+1, K, ans);
        else
        {
            getUpwards(root->right, child, k+1, K, ans);
            getUpwards(root->left, child, k+1, K, ans);
        }
    }

    void getDownwards(TreeNode* root, vector<int>& ans, int k, int& K)
    {
        if(root==NULL)
            return;

        if(k==K)
            ans.push_back(root->val);

        getDownwards(root->left, ans, k+1, K);
        getDownwards(root->right, ans, k+1, K);
    }

    void getParents(TreeNode* root, TreeNode* target, vector<TreeNode*>& parents, bool& found)
    {
        if(root==NULL)
            return;

        if(root==target)
        {
            found=true;
            return;
        }

        parents.push_back(root);

        getParents(root->left, target, parents, found);
        if(!found)
            getParents(root->right, target, parents, found);

        if(!found)
            parents.pop_back();
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        vector<int> ans;

        vector<TreeNode*> parents;
        bool found=false;
        getParents(root, target, parents, found);

        int j=1;
        TreeNode* child=target;
        getDownwards(target, ans, 0, K);
        for(int i=parents.size()-1; i>=0; i--)
        {
            if(j>K)
                break;

            getUpwards(parents[i], child, j, K, ans);
            child=parents[i];
            j++;
        }

        return ans;
    }
};
