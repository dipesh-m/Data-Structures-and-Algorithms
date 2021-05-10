class Solution {
public:
    int maxDepth(string s)
    {
        int ans=0, c=0;
        for(auto& z:s)
        {
            if(z=='(')
                c++;
            else if(z==')')
                c--;

            ans=max(ans, c);
        }

        return ans;
    }
};
