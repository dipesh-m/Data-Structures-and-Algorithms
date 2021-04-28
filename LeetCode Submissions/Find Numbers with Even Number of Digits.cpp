class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int ans=0;
        for(auto z:nums)
        {
            int count=0;
            while(z>0)
            {
                count++;
                z/=10;
            }

            if(count%2==0)
                ans++;
        }

        return ans;
    }
};
