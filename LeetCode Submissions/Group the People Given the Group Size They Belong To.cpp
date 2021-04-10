class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<vector<int>>> um;

        for(int i=0; i<groupSizes.size(); i++)
        {
            if(um.count(groupSizes[i])>0)
            {
             if(um.at(groupSizes[i]).at(um.at(groupSizes[i]).size()-1).size()==groupSizes[i])
                {
                    vector<int> im;
                    im.push_back(i);
                    um.at(groupSizes[i]).push_back(im);
                }
                else
                {
                    um.at(groupSizes[i]).at(um.at(groupSizes[i]).size()-1).push_back(i);
                }
            }
            else
            {
                vector<vector<int>> big;
                vector<int> im;
                im.push_back(i);
                big.push_back(im);
                um[groupSizes[i]]=big;
            }
        }

        vector<vector<int>> ans;
        for(auto it=um.begin(); it!=um.end(); it++)
        {
            for(int i=0; i<it->second.size(); i++)
                ans.push_back(it->second.at(i));
        }

        return ans;
    }
};
