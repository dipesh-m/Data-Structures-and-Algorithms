/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* head, TreeNode* root)
    {
        if(root==NULL)
            return false;

        if(root->val==head->val && head->next==NULL)
            return true;

        if(root->val==head->val)
        {
            return helper(head->next, root->left) || helper(head->next, root->right);
        }

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(root==NULL)
            return false;

        if(helper(head, root))
            return true;

        if(isSubPath(head, root->left))
            return true;

        if(isSubPath(head, root->right))
            return true;

        return false;
    }
};
