class Solution {
public:
    int isPrefixOfWord(string s, string searchWord)
    {
        int i=0, j, ans=1;
        bool toCheck=false;
        while(i<s.size())
        {
            toCheck=true;
            j=0;
            while(i<s.size() && s[i]!=' ')
            {
                if(toCheck)
                {
                    if(s[i]==searchWord[j])
                        j++;
                    else
                        toCheck=false;

                    if(j==searchWord.size())
                        return ans;

                    i++;
                }
                else
                    i++;
            }

            i++;
            ans++;
        }

        return -1;
    }
};
