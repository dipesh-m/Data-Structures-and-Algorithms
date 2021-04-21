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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL && l2==NULL)
            return NULL;

        if(l1==NULL)
            return l2;

        if(l2==NULL)
            return l1;

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                if(head==NULL)
                {
                    head=l1;
                    tail=l1;
                }
                else
                {
                    tail->next=l1;
                    tail=l1;
                }

                l1=l1->next;
            }
            else
            {
                if(head==NULL)
                {
                    head=l2;
                    tail=l2;
                }
                else
                {
                    tail->next=l2;
                    tail=l2;
                }

                l2=l2->next;
            }
        }

        while(l1!=NULL)
        {
            tail->next=l1;
            tail=l1;
            l1=l1->next;
        }

        while(l2!=NULL)
        {
            tail->next=l2;
            tail=l2;
            l2=l2->next;
        }

        return head;
    }
};
