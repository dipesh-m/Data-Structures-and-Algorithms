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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;

        ListNode* first=head;
        ListNode* second=head->next;

        ListNode* even=head;
        ListNode* odd=head->next;

        ListNode* temp=NULL;
        while(even!=NULL && odd!=NULL)
        {
            if(even->next->next==NULL)
            {
                temp=even;
            }

            even->next=even->next->next;
            if(odd->next!=NULL)
                odd->next=odd->next->next;

            even=even->next;
            odd=odd->next;
        }

        if(even==NULL)
        {
            temp->next=second;
        }
        else
        {
            even->next=second;
        }

        return first;
    }
};
