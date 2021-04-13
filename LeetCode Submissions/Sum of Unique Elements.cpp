class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        unordered_map<int, int> um;
        int ans=0;

        for(int i=0; i<nums.size(); i++)
        {
            um[nums.at(i)]++;
        }

        for(auto it=um.begin(); it!=um.end(); it++)
        {
            if(it->second==1)
                ans+=it->first;
        }

        return ans;
    }
};
