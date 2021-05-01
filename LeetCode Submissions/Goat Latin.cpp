class Solution {
public:
    string toGoatLatin(string S)
    {
        unordered_set<char> us({'a','e','i','o','u','A','E','I','O','U',});
        string ans;

        int i=0, c=1;
        while(i<S.size())
        {
            char f=S[i];
            bool vow=false;
            if(us.count(S[i])>0)
                vow=true;

            if(vow==false)
                i++;

            while(i<S.size() && S[i]!=' ')
            {
                ans+=S[i];
                i++;
            }

            if(vow)
                ans+="ma";
            else
            {
                ans+=f;
                ans+="ma";
            }

            for(int j=0; j<c; j++)
                ans+='a';

            c++;

            if(i<S.size())
                ans+=' ';

            i++;
        }

        return ans;
    }
};
