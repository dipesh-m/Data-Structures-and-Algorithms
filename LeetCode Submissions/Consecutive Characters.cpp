class Solution {
public:
    int maxPower(string s)
    {
        int ans=1, i=0;
        while(i<s.size())
        {
            if(i+1<s.size() && s[i+1]==s[i])
            {
                int j=i;
                while(i+1<s.size() && s[i+1]==s[i])
                    i++;

                ans=max(ans, i-j+1);
            }
            else
                i++;
        }

        return ans;
    }
};
