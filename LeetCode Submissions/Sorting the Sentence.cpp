class Solution {
public:
    string sortSentence(string s)
    {
        vector<string> ans(10);
        int i=0;
        while(i<s.size())
        {
            ans[0]="";
            while(i<s.size())
            {
                ans[0]+=s[i];
                i++;

                if(s[i]>='1' && s[i]<='9')
                    break;
            }

            ans[s[i]-'0']=ans[0];

            i+=2;
        }

        s="";
        i=1;
        while(i<10)
        {
            if(ans[i]!="")
            {
                s+=ans[i]+' ';
                i++;
            }
            else
                i++;
        }

        s.pop_back();
        return s;
    }
};
