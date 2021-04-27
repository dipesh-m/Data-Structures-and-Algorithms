class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int count=0;
        for(auto z:arr)
        {
            if(z!=count+1)
            {
                while(count!=z-1)
                {
                    count++;
                    k--;

                    if(k==0)
                        return count;
                }
            }

            count=z;
        }

        if(k!=0)
        {
            while(k!=0)
            {
                count++;
                k--;
            }
        }

        return count;
    }
};
