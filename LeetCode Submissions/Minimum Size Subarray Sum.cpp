class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int begin=0, end=0, counter=1, ans=INT_MAX, curr=0;
        while(end<nums.size())
        {
            curr+=nums[end];
            if(curr>=target)
                counter--;
            end++;

            while(counter==0)
            {
                if(curr>=target)
                    ans=min(ans, end-begin);
                else
                    counter++;

                curr-=nums[begin];
                begin++;
            }
        }

        return ans==INT_MAX ? 0 : ans;
    }
};
