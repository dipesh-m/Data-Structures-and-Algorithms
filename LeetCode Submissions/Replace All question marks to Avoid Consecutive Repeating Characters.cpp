class Solution {
public:
    string modifyString(string s)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='?')
            {
                if(i-1>=0 && i+1<s.size())
                {
                    s[i]=s[i-1]+1;

                    if(s[i]==s[i+1])
                        s[i]=s[i+1]+1;
                }
                else if(i-1>=0)
                    s[i]=s[i-1]+1;
                else if(i+1<s.size())
                {
                    if(s[i+1]!='?')
                        s[i]=s[i+1]+1;
                    else
                        s[i]='a';
                }
                else
                    s[i]='a';

                if(s[i]=='z'+1)
                    s[i]='a';

                if(s[i]==s[i+1])
                    s[i]=s[i+1]+1;

                cout<<s<<" ";
            }
        }

        return s;
    }
};
