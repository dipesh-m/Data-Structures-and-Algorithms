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
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* smallerOutput=reverseLL(head->next);

        ListNode* tail=head->next;
        tail->next=head;
        head->next=NULL;

        return smallerOutput;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left==right)
            return head;

        ListNode* temp=head;
        for(int i=0; i<left-2; i++)
        {
            temp=temp->next;
        }

        ListNode* endingNode=head;
        for(int i=0; i<right-1; i++)
        {
            endingNode=endingNode->next;
        }

        ListNode* last=endingNode->next;
        endingNode->next=NULL;

        ListNode* rev=NULL;
        if(left==1)
        {
            rev=reverseLL(head);
            ListNode* move=rev;
            while(move->next!=NULL)
            {
                move=move->next;
            }
            move->next=last;
            return rev;
        }
        else
        {
            rev=reverseLL(temp->next);
            temp->next=rev;
            while(rev->next!=NULL)
            {
                rev=rev->next;
            }
            rev->next=last;

            return head;
        }




    }
};
