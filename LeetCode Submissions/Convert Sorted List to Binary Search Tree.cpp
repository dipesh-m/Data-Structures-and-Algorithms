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
    ListNode* cutPrevAndGetMid(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* first=head;
        ListNode* second=head;

        while(second!=NULL && second->next!=NULL)
        {
            prev=first;
            first=first->next;
            second=second->next->next;
        }

        if(prev!=NULL)
            prev->next=NULL;

        return first;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }

        ListNode* mid=cutPrevAndGetMid(head);

        TreeNode* root=new TreeNode(mid->val);
        if(mid==head)
        {
            return root;
        }

        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);

        return root;
    }
};
