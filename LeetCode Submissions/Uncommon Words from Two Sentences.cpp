class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        unordered_map<string, int> us;

        int i=0;
        while(i<A.size())
        {
            string word;
            while(i<A.size() && A.at(i)!=' ')
            {
                word+=A.at(i);
                i++;
            }

            us[word]++;
            i++;
        }

        i=0;
        while(i<B.size())
        {
            string word;
            while(i<B.size() && B.at(i)!=' ')
            {
                word+=B.at(i);
                i++;
            }

            us[word]++;
            i++;
        }

        vector<string> ans;
        for(auto z:us)
        {
            if(z.second==1)
                ans.push_back(z.first);
        }

        return ans;
    }
};
