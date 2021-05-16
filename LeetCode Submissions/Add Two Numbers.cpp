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
        ListNode* res=new ListNode(0);
        ListNode* curr=res;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry)
        {
            int total=((l1==NULL ? 0 : l1->val) + (l2==NULL ? 0 : l2->val))+carry;
            carry=total>9 ? total/10 : 0;

            curr->next=new ListNode(total%10);
            curr=curr->next;

            l1=l1==NULL ? l1 : l1->next;
            l2=l2==NULL ? l2 : l2->next;
        }

        return res->next;
    }
};
