class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
    {
        unordered_map<int, pair<int, string>> um;
        for(int i=0; i<indexes.size(); i++)
        {
            if(s.substr(indexes.at(i), sources.at(i).size())==sources.at(i))
            {
                um[indexes.at(i)]=make_pair(sources.at(i).size(), targets.at(i));
            }
        }

        string ans;
        int i=0;
        while(i<s.size())
        {
            if(um.count(i)>0)
            {
                ans+=um.at(i).second;

                i+=um.at(i).first;
                continue;
            }

            if(i<s.size())
                ans+=s.at(i);

            i++;
        }

        return ans;
    }
};
