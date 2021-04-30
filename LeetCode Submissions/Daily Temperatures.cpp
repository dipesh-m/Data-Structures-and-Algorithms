class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        vector<int> ans(T.size());

        stack<pair<int, int>> st;
        int i=T.size()-1;

        while(i>=0)
        {
            while(!st.empty() && st.top().first<=T[i])
                st.pop();

            if(st.empty())
                ans[i]=0;
            else
                ans[i]=st.top().second-i;

            st.push(make_pair(T[i], i));
            i--;
        }

        return ans;
    }
};
