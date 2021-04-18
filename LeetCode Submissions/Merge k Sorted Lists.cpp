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
    ListNode* merge2SortedLLs(ListNode* node1, ListNode* node2)
    {
        if(node1==NULL)
            return node2;

        if(node2==NULL)
            return node1;

        ListNode* node3=NULL;
        ListNode* tail3=NULL;

        while(node1!=NULL && node2!=NULL)
        {
            if(node1->val<=node2->val)
            {
                if(node3==NULL)
                {
                    node3=node1;
                    tail3=node1;
                }
                else
                {
                    tail3->next=node1;
                    tail3=node1;
                }

                node1=node1->next;
            }
            else
            {
                if(node3==NULL)
                {
                    node3=node2;
                    tail3=node2;
                }
                else
                {
                    tail3->next=node2;
                    tail3=node2;
                }

                node2=node2->next;
            }
        }

        while(node1!=NULL)
        {
            tail3->next=node1;
            tail3=node1;

            node1=node1->next;
        }

        while(node2!=NULL)
        {
            tail3->next=node2;
            tail3=node2;

            node2=node2->next;
        }

        return node3;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size()==0)
            return NULL;

        if(lists.size()==1)
            return lists.at(0);

        ListNode* ans=NULL;
        for(auto z:lists)
        {
            ans=merge2SortedLLs(ans, z);
        }

        return ans;
    }
};
