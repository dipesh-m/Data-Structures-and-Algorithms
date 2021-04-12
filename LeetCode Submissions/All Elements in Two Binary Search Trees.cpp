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
    void inorder(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    void merge2SortedArr(vector<int>& ans1, vector<int>& ans2, int si1, int ei1, int si2, int ei2, vector<int>& ans)
    {
        int i=si1, j=si2;
        while(i<=ei1 && j<=ei2)
        {
            if(ans1.at(i)<=ans2.at(j))
            {
                ans.push_back(ans1.at(i));
                i++;
            }
            else
            {
                ans.push_back(ans2.at(j));
                j++;
            }
        }

        while(i<=ei1)
        {
            ans.push_back(ans1.at(i));
            i++;
        }

        while(j<=ei2)
        {
            ans.push_back(ans2.at(j));
            j++;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ans;
        vector<int> ans1;
        vector<int> ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);
        merge2SortedArr(ans1, ans2, 0, ans1.size()-1, 0, ans2.size()-1, ans);
        return ans;
    }
};
