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
    void reorderList(ListNode* head)
    {
        ListNode* first=head;
        ListNode* second=head;

        while(second->next!=NULL && second->next->next!=NULL)
        {
            first=first->next;
            second=second->next->next;
        }

        if(first==second)
            return;

        ListNode* curr=first->next;
        first->next=NULL;

        second=NULL;
        while(curr!=NULL)
        {
            ListNode* ahead=curr->next;
            curr->next=second;
            second=curr;
            curr=ahead;
        }

        first=head;

        ListNode* prevFirst=NULL;
        ListNode* prevSecond=NULL;
        while(first!=NULL && second!=NULL)
        {
            prevFirst=first;
            first=first->next;
            prevFirst->next=second;

            prevSecond=second;
            second=second->next;
            prevSecond->next=first;
        }
    }
};
