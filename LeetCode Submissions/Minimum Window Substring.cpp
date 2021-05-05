class Solution {
public:
    string minWindow(string s, string t)
    {
        if(t.size()>s.size())
            return "";

        unordered_map<char, int> um;
        for(auto& z:t)
            um[z]++;

        int begin=0, end=0, counter=um.size(), ansLen=INT_MAX;
        string ans;
        while(end<s.size())
        {
            if(um.count(s[end])>0)
            {
                um.at(s[end])--;
                if(um.at(s[end])==0)
                    counter--;
            }

            end++;

            while(counter==0)
            {
                if(um.count(s[begin])>0)
                {
                    if(um.at(s[begin])==0)
                        counter++;
                    um.at(s[begin])++;
                }

                if(end-begin<ansLen)
                {
                    ans=s.substr(begin, end-begin);
                    ansLen=end-begin;
                }

                begin++;
            }
        }

        return ans;
    }
};
