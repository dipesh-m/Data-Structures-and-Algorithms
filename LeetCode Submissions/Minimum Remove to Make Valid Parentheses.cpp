class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int c=0;
        stack<int> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')' && !st.empty())
                st.pop();
            else if(s[i]==')')
            {
                s[i]='#';
                c++;
            }
        }

        string ans(s.size()-(st.size()+c), '*');
        int j=ans.size()-1;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(!st.empty() && i==st.top())
            {
                st.pop();
                continue;
            }

            if(s[i]!='#')
            {
                ans[j]=s[i];
                j--;
            }
        }

        return ans;
    }
};
