class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans=nums;
        unordered_map<int, int> um;
        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++)
        {
            if(um.count(ans.at(i))>0)
                continue;
            else
            {
                um[ans.at(i)]=i;
            }
        }

        ans.clear();
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(um.at(nums.at(i)));
        }

        return ans;
    }
};
