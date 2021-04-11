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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if(nums.size()==0)
            return NULL;

        int max=*max_element(nums.begin(), nums.end());
        int maxIndex=max_element(nums.begin(), nums.end())-nums.begin();

        TreeNode* node=new TreeNode(max);

        vector<int> first;
        for(int i=0; i<maxIndex; i++)
        {
            first.push_back(nums.at(i));
        }
        vector<int> second;
        for(int i=maxIndex+1; i<nums.size(); i++)
        {
            second.push_back(nums.at(i));
        }

        node->left=constructMaximumBinaryTree(first);
        node->right=constructMaximumBinaryTree(second);

        return node;
    }
};
