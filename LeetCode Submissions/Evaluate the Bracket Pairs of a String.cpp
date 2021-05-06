class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        if(s.size()<3)
            return s;

        unordered_map<string, string> um;
        for(auto& z:knowledge)
            um[z[0]]=z[1];

        string ans, x;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                i++;
                x="";
                while(s[i]!=')')
                {
                    x+=s[i];
                    i++;
                }

                if(um.count(x)>0)
                    ans+=um.at(x);
                else
                    ans+='?';

                i++;
            }
            else
            {
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
};
