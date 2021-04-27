class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> us;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>k)
                us.erase(nums.at(i-k-1));

            if(us.count(nums[i])>0)
                return true;

            us.insert(nums[i]);
        }

        return false;
    }
};
