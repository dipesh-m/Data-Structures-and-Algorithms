class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        vector<int> ans;

        int maxDiag=INT_MIN;
        unordered_map<int, vector<int>> um;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                um[i+j].emplace_back(nums[i][j]);
                maxDiag=max(maxDiag, i+j);
            }
        }

        for(int i=0; i<=maxDiag; i++)
        {
            for(int j=um[i].size()-1; j>=0; j--)
                ans.emplace_back(um[i][j]);
        }

        return ans;
    }
};
