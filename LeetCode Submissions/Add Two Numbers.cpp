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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ans=NULL;
        ListNode* tail=NULL;
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            int total=(l1->val+l2->val)+carry;
            carry=total>9 ? total/10 : 0;

            ListNode* newNode=new ListNode(total%10);
            if(ans==NULL)
            {
                ans=newNode;
                tail=newNode;
            }
            else
            {
                tail->next=newNode;
                tail=newNode;
            }

            l1=l1->next;
            l2=l2->next;
        }

        if(l1==NULL && l2==NULL && carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            tail->next=newNode;
            tail=newNode;

            return ans;
        }
        else if(l1==NULL)
        {
            while(l2!=NULL)
            {
                int total=(l2->val)+carry;
                carry=total>9 ? total/10 : 0;
                ListNode* newNode=new ListNode(total%10);
                tail->next=newNode;
                tail=newNode;

                l2=l2->next;
            }

            if(carry!=0)
            {
                ListNode* newNode=new ListNode(carry);
                tail->next=newNode;
                tail=newNode;
            }

            return ans;
        }

        while(l1!=NULL)
        {
            int total=(l1->val)+carry;
            carry=total>9 ? total/10 : 0;
            ListNode* newNode=new ListNode(total%10);
            tail->next=newNode;
            tail=newNode;

            l1=l1->next;
        }

        if(carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            tail->next=newNode;
            tail=newNode;
        }

        return ans;
    }
};
