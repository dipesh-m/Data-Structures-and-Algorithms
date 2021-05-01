class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> us;
        for(auto& z:emails)
        {
            string temp;
            int i=0;
            while(i<z.size())
            {
                if(z[i]=='@')
                {
                    temp+=z.substr(i);
                    break;
                }
                else if(z[i]=='+')
                {
                    while(z[i]!='@')
                        i++;

                    temp+=z.substr(i);
                    break;
                }
                else if(z[i]=='.')
                {
                    i++;
                }
                else
                {
                    temp+=z[i];
                    i++;
                }
            }

            us.insert(temp);
        }

        return us.size();
    }
};
