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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        int count=0;

        ListNode* temp=list1;
        for(int i=0; i<a-1; i++)
        {
            temp=temp->next;
            count++;
        }

        ListNode* temp1=NULL;
        temp1=temp;

        for(int i=0; i<b-count; i++)
        {
            temp=temp->next;
        }

        ListNode* last=NULL;
        last=temp->next;
        temp->next=NULL;

        ListNode* sec=list2;
        while(sec->next!=NULL)
            sec=sec->next;

        temp1->next=list2;
        sec->next=last;

        return list1;
    }
};
