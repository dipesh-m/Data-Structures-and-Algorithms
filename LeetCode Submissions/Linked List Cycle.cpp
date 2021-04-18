/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return false;

        ListNode* first=head->next;
        ListNode* second=head->next->next;

        while(second!=first)
        {
            if(second==NULL || second->next==NULL)
                return false;

            first=first->next;
            second=second->next->next;
        }

        return true;
    }
};
