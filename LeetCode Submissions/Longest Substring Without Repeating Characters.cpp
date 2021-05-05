class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size()<=1)
            return s.size();

        vector<int> um(256,0);
        int begin=0, end=0, ans=0, counter=0;
        while(end<s.size())
        {
            um[s[end]]++;
            if(um[s[end]]>1)
                counter++;

            end++;

            while(counter>0)
            {
                if(um[s[begin]]>1)
                    counter--;
                um[s[begin]]--;

                begin++;
            }

            ans=max(ans, end-begin);
        }

        return ans;
    }
};
