//O(1) SPACE
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
    ListNode* insertionSortList(ListNode* head)
    {
        if(head->next==NULL)
            return head;

        ListNode* temp=head->next;
        head->next=NULL;

        ListNode* curr=NULL;
        ListNode* ahead=NULL;
        while(temp!=NULL)
        {
            curr=head;
            while(curr->next!=NULL && temp->val>curr->next->val)
                curr=curr->next;

            ahead=temp->next;

            if(curr==head && temp->val<=curr->val)
            {
                temp->next=head;
                head=temp;
            }
            else
            {
                temp->next=curr->next;
                curr->next=temp;
            }

            temp=ahead;
        }

        return head;
    }
};

//SWAPPING NODES
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
    ListNode* insertionSortList(ListNode* head)
    {
        if(head->next==NULL)
            return head;

        unordered_map<ListNode*, ListNode*> um;
        ListNode* temp=head;
        for(; temp!=NULL; temp=temp->next)
            um[temp->next]=temp;

        um[head]=NULL;

        temp=head->next;
        ListNode* parent=NULL;
        while(temp!=NULL)
        {
            parent=um.at(temp);
            while(parent!=NULL && temp->val<parent->val)
                parent=um.at(parent);

            ListNode* ahead=temp->next;
            um.at(temp)->next=ahead;
            um.at(ahead)=um.at(temp);

            if(parent==NULL)
            {
                um.at(head)=temp;
                um.at(temp)=NULL;

                temp->next=head;

                head=temp;
            }
            else
            {
                um.at(parent->next)=temp;
                um.at(temp)=parent;

                temp->next=parent->next;
                parent->next=temp;
            }

            temp=ahead;
        }

        return head;
    }
};
