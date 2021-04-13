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
    int numComponents(ListNode* head, vector<int>& G)
    {
        if(head->next==NULL)
        {
            if(G.at(0)==head->val)
                return 1;
            else
                return 0;
        }

        unordered_set<int> us;
        for(int i=0; i<G.size(); i++)
        {
            us.insert(G.at(i));
        }

        int ans=0;
        ListNode* curr=head;
        bool before=false;
        while(curr!=NULL)
        {
            if(us.count(curr->val)>0)
            {
                before=true;
                curr=curr->next;
                continue;
            }

            if(us.count(curr->val)==0 && before)
            {
                ans++;
                before=false;
                curr=curr->next;
                continue;
            }

            curr=curr->next;
        }

        if(before)
            ans++;

        return ans;
    }
};
