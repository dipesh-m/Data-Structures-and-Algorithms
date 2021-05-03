class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(auto& z:s)
        {
            if(z=='(' || z=='{' || z=='[')
            {
                st.push(z);
                continue;
            }

            if(z==')' && (st.empty() || st.top()!='('))
                return false;
            else if(z=='}' && (st.empty() || st.top()!='{'))
                return false;
            else if(z==']' && (st.empty() || st.top()!='['))
                return false;

            st.pop();
        }

        return st.empty();
    }
};
