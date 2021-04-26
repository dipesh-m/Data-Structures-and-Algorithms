class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> um;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            if(um.count(target-nums[i])>0)
            {
                ans.push_back(um.at(target-nums[i]));
                ans.push_back(i);
                break;
            }
            else
                um[nums[i]]=i;
        }

        return ans;
    }
};
