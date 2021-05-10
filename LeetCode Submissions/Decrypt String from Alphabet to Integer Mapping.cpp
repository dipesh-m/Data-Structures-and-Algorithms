class Solution {
public:
    string freqAlphabets(string s)
    {
        string ans;
        int i=0;
        while(i<s.size())
        {
            if(i+2<s.size() && s[i+2]=='#')
            {
                ans+='a'-1+((s[i]-'0')*10+(s[i+1]-'0'));
                i+=3;
            }
            else
            {
                ans+='a'-1+(s[i]-'0');
                i++;
            }
        }

        return ans;
    }
};
