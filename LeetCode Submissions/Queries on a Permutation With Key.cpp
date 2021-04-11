class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        unordered_map<int, int> um;
        for(int i=1; i<=m; i++)
        {
            um[i]=i-1;
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int pos=um.at(queries.at(i));
            ans.push_back(pos);

            for(auto z=um.begin(); z!=um.end(); z++)
            {
                if(z->second==pos)
                {
                    (z->second)=0;
                }
                else if(z->second<pos)
                {
                    (z->second)++;
                }
            }
        }

        return ans;
    }
};
