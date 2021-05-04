class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int f=0, s=0;
        for(auto& z:nums)
        {
            if(z>f)
            {
                s=f;
                f=z;
            }
            else if(z>s)
                s=z;
        }

        return (f-1)*(s-1);
    }
};
