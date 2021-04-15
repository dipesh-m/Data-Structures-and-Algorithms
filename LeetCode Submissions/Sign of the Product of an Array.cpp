class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        int p=1;
        for(auto z:nums)
        {
            if(z==0) return 0;

            if(z<0) p*=-1;
        }

        if(p<0) return -1;

        return 1;
    }
};
