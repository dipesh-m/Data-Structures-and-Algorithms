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

 //O(n) time and O(n) space

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(root==NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return false;

        vector<int> arr;
        inorder(root, arr);

        int i=0, j=arr.size()-1;
        while(i<j)
        {
            if(arr[i]+arr[j]==k)
                return true;
            else if(arr[i]+arr[j]<k)
                i++;
            else
                j--;
        }

        return false;
    }
};


//O(nlogn) time and O(1) space ignoring recursion stack

class Solution {
public:
    bool bstSearch(TreeNode* root, TreeNode* originalSent, int& target)
    {
        if(root==NULL)
            return false;

        if(root!=originalSent && root->val==target)
            return true;
        else if(root->val>target)
            return bstSearch(root->left, originalSent, target);
        else
            return bstSearch(root->right, originalSent, target);

        return false;
    }

    bool helper(TreeNode* root, TreeNode* orig, int& target)
    {
        if(root==NULL)
            return false;

        int toFind=target-root->val;

        if(bstSearch(orig, root, toFind))
            return true;

        return helper(root->left, orig, target) || helper(root->right, orig, target);
    }

    bool findTarget(TreeNode* root, int k)
    {
        return helper(root, root, k);
    }
};
