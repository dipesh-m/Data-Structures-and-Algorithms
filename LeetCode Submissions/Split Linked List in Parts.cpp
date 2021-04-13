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

    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*> ans;

        if(head==NULL)
        {
            for(int i=0; i<k; i++)
            {
                ans.push_back(NULL);
            }

            return ans;
        }

        int s=size(head);
        ListNode* prev=head;
        ListNode* curr=head->next;

        if(k>=s)
        {
            while(prev!=NULL)
            {
                prev->next=NULL;
                ans.push_back(prev);
                prev=curr;
                if(curr!=NULL)
                    curr=curr->next;
                k--;
            }

            while(k>0)
            {
                ans.push_back(NULL);
                k--;
            }

            return ans;
        }

        int groupSize=s/k;
        int remaining=s%k;

        ListNode* headHere=prev;
        while(prev!=NULL)
        {
            int c=remaining>0 ? groupSize : groupSize-1;
            for(int i=0; i<c; i++)
            {
                prev=curr;
                curr=curr->next;
            }

            prev->next=NULL;
            prev=curr;
            if(curr!=NULL)
                curr=curr->next;
            ans.push_back(headHere);

            headHere=prev;

            if(remaining>0)
            {
                remaining--;
            }
        }

        return ans;
    }
};
