class Solution {
public:
    string longestPalindrome(string s)
    {
        int i=0, x, y, start=0, end=0, maxSize=1;
        while(i<s.size())
        {
            x=i-1, y=i+1;
            while(x>=0 && y<s.size())
            {
                if(s[x]==s[y])
                {
                    x--;
                    y++;
                }
                else
                    break;
            }

            x++;
            y--;

            if(y-x+1>maxSize)
            {
                start=x;
                end=y;
                maxSize=y-x+1;
            }

            x=i, y=i+1;
            while(x>=0 && y<s.size())
            {
                if(s[x]==s[y])
                {
                    x--;
                    y++;
                }
                else
                    break;
            }

            x++;
            y--;

            if(y-x+1>maxSize)
            {
                start=x;
                end=y;
                maxSize=y-x+1;
            }

            i++;
        }

        return s.substr(start, end-start+1);
    }
};
