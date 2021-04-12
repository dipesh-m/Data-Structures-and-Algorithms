class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
    {
        unordered_map<int, pair<int, unordered_set<int>>> um;

        for(int i=0; i<logs.size(); i++)
        {
            if(um.count(logs.at(i).at(0))>0)
            {
                if(um.at(logs.at(i).at(0)).second.count(logs.at(i).at(1))==0)
                {
                    um.at(logs.at(i).at(0)).first++;
                    um.at(logs.at(i).at(0)).second.insert(logs.at(i).at(1));
                }
            }
            else
            {
                unordered_set<int> im;
                im.insert(logs.at(i).at(1));
                um.insert(make_pair(logs.at(i).at(0), make_pair(1, im)));
            }
        }

        vector<int> ans(k, 0);
        for(auto it=um.begin(); it!=um.end(); it++)
        {
            ans.at((it->second).first-1)++;
        }

        return ans;
    }
};
