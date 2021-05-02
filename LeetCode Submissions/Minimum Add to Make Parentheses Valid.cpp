class Solution {
public:
    int minAddToMakeValid(string S)
    {
        int c=0;
        stack<char> st;
        for(auto& z:S)
        {
            if(z=='(')
                st.push('(');
            else if(!st.empty())
                st.pop();
            else
                c++;
        }

        return st.size()+c;
    }
};
