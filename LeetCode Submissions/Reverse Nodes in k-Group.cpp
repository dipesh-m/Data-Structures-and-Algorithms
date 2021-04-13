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

    pair<ListNode*, ListNode*> reverse(ListNode* head)
    {
        pair<ListNode*, ListNode*> output;
        output.second=head;

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }

        output.first=prev;
        return output;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int s=size(head);
        if(s<=1)
            return head;

        if(k==1)
            return head;

        ListNode* ans=NULL;

        int remainingNodes=(s%k);
        ListNode* sendHead=head;
        ListNode* sendTail=head;
        ListNode* nextSendHead=head;
        pair<ListNode*, ListNode*> prevRec;
        prevRec.first=NULL;
        prevRec.second=NULL;
        for(int i=0; i<(s/k); i++)
        {
            for(int j=0; j<k-1; j++)
            {
                sendTail=sendTail->next;
            }
            nextSendHead=sendTail->next;
            sendTail->next=NULL;
            pair<ListNode*, ListNode*> rec=reverse(sendHead);
            if(i!=0)
            {
                prevRec.second->next=rec.first;
            }
            prevRec=rec;
            sendHead=nextSendHead;
            sendTail=nextSendHead;

            if(i==0)
            {
                ans=rec.first;
            }
        }

        if(remainingNodes>0)
        {
            prevRec.second->next=nextSendHead;
        }

        return ans;
    }
};
