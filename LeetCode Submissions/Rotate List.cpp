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
    int size(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }

        return count;
    }

    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL)
            return NULL;

        int s=size(head);
        k=k%(s);
        if(s==1 || k==0)
            return head;

        ListNode* first=NULL;
        ListNode* second=head;

        for(int i=0; i<(s-k); i++)
        {
            if(i==0)
            {
                first=head;
                second=second->next;
                continue;
            }

            first=first->next;
            second=second->next;
        }

        first->next=NULL;
        first=head;
        head=second;

        while(second->next!=NULL)
        {
            second=second->next;
        }

        second->next=first;
        return head;
    }
};
