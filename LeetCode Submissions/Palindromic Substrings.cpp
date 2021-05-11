class Solution {
public:
    int countSubstrings(string s)
    {
        int i=0, x, y, ans=s.size();
        while(i<s.size())
        {
            x=i-1, y=i+1;
            while(x>=0 && y<s.size())
            {
                if(s[x]==s[y])
                {
                    ans++;
                    x--;
                    y++;
                }
                else
                    break;
            }

            x=i, y=i+1;
            while(x>=0 && y<s.size())
            {
                if(s[x]==s[y])
                {
                    ans++;
                    x--;
                    y++;
                }
                else
                    break;
            }

            i++;
        }

        return ans;
    }
};
