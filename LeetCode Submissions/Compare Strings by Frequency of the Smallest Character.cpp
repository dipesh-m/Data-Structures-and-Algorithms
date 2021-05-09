class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        int map[26]={0};
        int freq[11]={0};
        for(int i=0; i<words.size(); i++)
        {
            if(i!=0)
                memset(map, 0, sizeof(map));

            char minChar=words[i].at(0);
            for(auto& z:words[i])
            {
                if(z<minChar)
                    minChar=z;

                map[z-'a']++;
            }

            for(int j=1; j<map[minChar-'a']; j++)
                freq[j]++;
        }

        vector<int> ans;

        for(int i=0; i<queries.size(); i++)
        {
            memset(map, 0, sizeof(map));

            char minChar=queries[i].at(0);
            for(auto& z:queries[i])
            {
                if(z<minChar)
                    minChar=z;

                map[z-'a']++;
            }

            cout<<minChar;
            ans.push_back(freq[map[minChar-'a']]);
        }

        return ans;
    }
};
