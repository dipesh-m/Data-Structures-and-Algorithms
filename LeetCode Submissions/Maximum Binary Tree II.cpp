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
    TreeNode* construct(vector<int>& nums)
    {
        if(nums.size()==0)
            return NULL;

        int maxEle=*max_element(nums.begin(), nums.end());
        int maxInd=max_element(nums.begin(), nums.end())-nums.begin();

        TreeNode* root=new TreeNode(maxEle);

        vector<int> first;
        for(int i=0; i<maxInd; i++)
            first.push_back(nums.at(i));

        vector<int> second;
        for(int i=maxInd+1; i<nums.size(); i++)
            second.push_back(nums.at(i));

        root->left=construct(first);
        root->right=construct(second);

        return root;
    }

    void fill(TreeNode* root, vector<int>& nums)
    {
        if(root==NULL)
            return;

        fill(root->left, nums);
        nums.push_back(root->val);
        fill(root->right, nums);
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val)
    {
        vector<int> nums;
        fill(root, nums);

        nums.push_back(val);
        return construct(nums);
    }
};
