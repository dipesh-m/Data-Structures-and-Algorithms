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
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int> ans;
        while(head!=NULL)
        {
            ans.push_back(head->val);
            head=head->next;
        }

        stack<int> st;
        int i=ans.size()-1;
        while(i>=0)
        {
            while(!st.empty() && ans[i]>=st.top())
                st.pop();

            int toAdd=ans[i];

            if(st.empty())
                ans[i]=0;
            else
                ans[i]=st.top();

            st.push(toAdd);
            i--;
        }

        return ans;
    }
};
