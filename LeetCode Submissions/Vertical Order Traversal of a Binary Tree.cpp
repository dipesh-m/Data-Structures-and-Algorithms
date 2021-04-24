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

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.second==b.second)
        return a.first<b.first;

    return a.second<b.second;
}

class Solution {
public:
    void helper(TreeNode* root, deque<vector<pair<int, int>>>& ans, int& zeroPos, int k, int depth)
    {
        if(root==NULL)
            return;

        if(k==0)
        {
            if(ans.size()==0)
            {
                vector<pair<int, int>> im;
                im.push_back(make_pair(root->val, depth));
                ans.push_back(im);
            }
            else
            {
                ans.at(zeroPos).push_back(make_pair(root->val, depth));
            }
        }
        else if(k<0)
        {
            if(zeroPos+k<0)
            {
                vector<pair<int, int>> im;
                im.push_back(make_pair(root->val, depth));
                ans.push_front(im);

                zeroPos++;
            }
            else
            {
                ans.at(zeroPos+k).push_back(make_pair(root->val, depth));
            }
        }
        else
        {
            if(zeroPos+k+1>ans.size())
            {
                vector<pair<int, int>> im;
                im.push_back(make_pair(root->val, depth));
                ans.push_back(im);
            }
            else
            {
                ans.at(zeroPos+k).push_back(make_pair(root->val, depth));
            }
        }

        helper(root->left, ans, zeroPos, k-1, depth+1);
        helper(root->right, ans, zeroPos, k+1, depth+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> empty;
        if(root==NULL)
            return empty;

        int zeroPos=0;
        deque<vector<pair<int, int>>> ans;

        helper(root, ans, zeroPos, 0, 0);

        vector<vector<int>> trueAns;
        for(auto z:ans)
        {
            sort(z.begin(), z.end(), comp);

            vector<int> im;
            for(auto y:z)
                im.push_back(y.first);

            trueAns.push_back(im);
        }

        return trueAns;
    }
};
