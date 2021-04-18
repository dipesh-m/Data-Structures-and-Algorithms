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
class Solution {
public:
    ListNode* helper(ListNode* head, int k)
    {
        if(head->next==NULL)
            return head;

        head->next=helper(head->next, k+1);

        if(k%2==0)
            return head;

        ListNode* out=head->next;
        head->next=head->next->next;
        out->next=head;

        return out;
    }

    ListNode* swapPairs(ListNode* head)
    {
        if(head==NULL)
            return NULL;

        if(head->next==NULL)
            return head;

        return helper(head, 1);
    }
};
