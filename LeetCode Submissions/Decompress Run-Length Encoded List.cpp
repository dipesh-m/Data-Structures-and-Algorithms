class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums)
    {
        vector<int> ans;
        for(int i=0, j=1; j<nums.size(); i+=2, j+=2)
        {
            for(int k=0; k<nums.at(i); k++)
            {
                ans.push_back(nums.at(j));
            }
        }

        return ans;
    }
};
