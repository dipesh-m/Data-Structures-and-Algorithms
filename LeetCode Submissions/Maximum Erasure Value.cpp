class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];

        unordered_map<int, int> um;
        for(auto& z:nums)
            um[z]=0;

        int begin=0, end=0, counter=0, curr=0, ans=INT_MIN;
        while(end<nums.size())
        {
            um.at(nums[end])++;
            if(um.at(nums[end])>1)
                counter++;

            curr+=nums[end];

            while(counter>0)
            {
                if(um.at(nums[begin])>1)
                    counter--;
                um.at(nums[begin])--;

                curr-=nums[begin];

                begin++;
            }

            if(counter==0)
                ans=max(ans, curr);

            end++;
        }

        return ans;
    }
};
