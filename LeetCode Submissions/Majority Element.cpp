class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int ans=nums.at(0);
        int count=1;
        for(auto z:nums)
        {
            if(z==ans)
                count++;
            else
                count--;

            if(count==0)
            {
                ans=z;
                count=1;
            }
        }

        count=0;
        for(auto z:nums)
        {
            if(z==ans)
                count++;
        }

        if(count>nums.size()/2)
            return ans;

        return -1;
    }
};
