//TOP - DOWN APPROACH
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
    ListNode* merge2SortedLLs(ListNode* head1, ListNode* head2)
    {
        if(head1==NULL)
            return head2;

        if(head2==NULL)
            return head1;

        ListNode* head3=NULL;
        ListNode* tail3=NULL;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                if(head3==NULL)
                {
                    head3=head1;
                    tail3=head1;
                }
                else
                {
                    tail3->next=head1;
                    tail3=head1;
                }

                head1=head1->next;
            }
            else
            {
                if(head3==NULL)
                {
                    head3=head2;
                    tail3=head2;
                }
                else
                {
                    tail3->next=head2;
                    tail3=head2;
                }

                head2=head2->next;
            }
        }

        while(head1!=NULL)
        {
            tail3->next=head1;
            tail3=head1;
            head1=head1->next;
        }

        while(head2!=NULL)
        {
            tail3->next=head2;
            tail3=head2;
            head2=head2->next;
        }

        return head3;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* first=head;
        ListNode* second=head;

        while(second->next!=NULL && second->next->next!=NULL)
        {
            first=first->next;
            second=second->next->next;
        }

        second=first->next;
        first->next=NULL;
        first=head;

        ListNode* a=mergeSort(first);
        ListNode* b=mergeSort(second);

        head=merge2SortedLLs(a,b);

        return head;
    }

    ListNode* sortList(ListNode* head)
    {
        if(head==NULL)
            return head;

        head=mergeSort(head);

        return head;
    }
};
