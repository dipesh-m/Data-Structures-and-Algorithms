class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;

        for(int i=0; i<strs.size(); i++)
        {
            string temp=strs.at(i);
            sort(strs.at(i).begin(), strs.at(i).end());

            if(um.count(strs.at(i))>0)
            {
                um.at(strs.at(i)).push_back(temp);
            }
            else
            {
                vector<string> im;
                im.push_back(temp);
                sort(strs.at(i).begin(), strs.at(i).end());

                um[strs.at(i)]=im;
            }
        }

        for(auto it=um.begin(); it!=um.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};
