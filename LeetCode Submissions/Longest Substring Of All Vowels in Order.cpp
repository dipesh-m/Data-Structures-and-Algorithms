class Solution {
public:
    int longestBeautifulSubstring(string word)
    {
        int ans=INT_MIN, i=0;
        while(i<word.size())
        {
            if(word[i]=='a')
            {
                int j=i;
                int k=1;
                char curr='a';

                while(j<word.size())
                {
                    if(k==5 && word[j]!='u')
                        break;

                    if(word[j]==curr)
                        j++;
                    else if(word[j]>curr)
                    {
                        curr=word[j];
                        k++;
                        j++;
                    }
                    else
                        break;
                }

                if(k==5)
                    ans=max(ans, (j-i));

                i=j;
            }
            else
                i++;
        }

        return ans==INT_MIN ? 0 : ans;
    }
};
