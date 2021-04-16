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
    TreeNode* helper(vector<int> nums, int si, int ei)
    {
        if(si>ei)
            return NULL;

        int mid=(si+ei)/2;
        TreeNode* newNode=new TreeNode(nums.at(mid));

        newNode->left=helper(nums, si, mid-1);
        newNode->right=helper(nums, mid+1, ei);

        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return helper(nums, 0, nums.size()-1);
    }
};
