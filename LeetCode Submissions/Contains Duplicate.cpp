//O(n) time and O(n) space

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> us;

        for(auto z:nums)
        {
            if(us.count(z)>0)
                return true;

            us.insert(z);
        }

        return false;
    }
};

//O(nlogn) time and O(1) space

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int i=0;
        while(i+1<nums.size())
        {
            if(nums[i]==nums[i+1])
                return true;

            i++;
        }

        return false;
    }
};
