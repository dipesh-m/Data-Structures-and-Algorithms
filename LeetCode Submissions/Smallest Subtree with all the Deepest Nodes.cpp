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
    void findLowestDepthAndCount(TreeNode* root, int& countLowest, int& lowestDepth, int k)
    {
        if(root==NULL)
            return;

        if(k==lowestDepth)
            countLowest++;
        else if(k>lowestDepth)
        {
            lowestDepth=k;
            countLowest=1;
        }

        findLowestDepthAndCount(root->left, countLowest, lowestDepth, k+1);
        findLowestDepthAndCount(root->right, countLowest, lowestDepth, k+1);
    }

    void getPathForCandidates(TreeNode* root, int& countLowest, int& lowestDepth, vector<vector<TreeNode*>>& cand, vector<TreeNode*>& im, int k)
    {
        if(root==NULL || countLowest==0)
            return;

        im.push_back(root);

        if(k==lowestDepth)
        {
            cand.push_back(im);
            countLowest--;
        }

        getPathForCandidates(root->left, countLowest, lowestDepth, cand, im, k+1);
        getPathForCandidates(root->right, countLowest, lowestDepth, cand, im, k+1);

        im.pop_back();
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        int countLowest=0;
        int lowestDepth=INT_MIN;
        findLowestDepthAndCount(root, countLowest, lowestDepth, 0);

        vector<vector<TreeNode*>> cand;
        vector<TreeNode*> im;
        getPathForCandidates(root, countLowest, lowestDepth, cand, im, 0);

        TreeNode* ans=NULL;

        int i=(cand.at(0).size())-1;
        while(i>=0)
        {
            TreeNode* node=cand.at(0).at(i);
            cout<<node->val<<" ";
            bool found=true;
            for(int j=0; j<cand.size(); j++)
            {
                if(cand.at(j).at(i)!=node)
                {
                    found=false;
                    break;
                }
            }

            if(found)
            {
                ans=node;
                break;
            }

            i--;
        }

        return ans;
    }
};
