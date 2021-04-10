class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=INT_MIN;

        for(int i=0; i<accounts.size(); i++)
        {
            int curr=0;
            for(int j=0; j<accounts.at(i).size(); j++)
            {
                curr+=accounts.at(i).at(j);
            }
            ans=max(ans, curr);
        }

        return ans;
    }
};
