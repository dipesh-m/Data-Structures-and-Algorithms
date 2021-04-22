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
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL)
        {
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return true;

        if(head->next->next==NULL)
        {
            if(head->val==head->next->val)
                return true;
            else
                return false;
        }

        ListNode* prev=NULL;
        ListNode* first=head;
        ListNode* second=head;

        while(second!=NULL && second->next!=NULL)
        {
            prev=first;
            first=first->next;
            second=second->next->next;
        }

        prev->next=NULL;

        ListNode* rev=NULL;
        if(second==NULL)
        {
            rev=reverseLL(first);
        }
        else
        {
            rev=reverseLL(first->next);
        }

        while(rev!=NULL && head!=NULL)
        {
            if(rev->val!=head->val)
                return false;

            rev=rev->next;
            head=head->next;
        }

        if(rev!=NULL || head!=NULL)
            return false;

        return true;
    }
};
