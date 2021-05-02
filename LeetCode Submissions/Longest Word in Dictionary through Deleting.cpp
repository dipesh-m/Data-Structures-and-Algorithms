class Solution {
public:
    bool checkSubsequence(string& s, string& x)
    {
        int i=0, j=0;
        while(i<s.size() && j<x.size())
        {
            if(s[i]==x[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }

        return j==x.size();
    }

    string findLongestWord(string s, vector<string>& d)
    {
        string ans;
        for(auto& str:d)
        {
            if(checkSubsequence(s, str))
            {
                if(ans=="")
                {
                    ans=str;
                    continue;
                }

                if(str.size()>ans.size())
                    ans=str;
                else if(str.size()==ans.size())
                    ans=min(ans, str);
            }
        }

        return ans;
    }
};
