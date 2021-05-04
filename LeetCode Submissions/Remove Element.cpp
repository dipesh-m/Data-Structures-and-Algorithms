class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i=0;
        for(auto& z:nums)
        {
            if(z!=val)
            {
                nums[i]=z;
                i++;
            }
        }

        return i;
    }
};
