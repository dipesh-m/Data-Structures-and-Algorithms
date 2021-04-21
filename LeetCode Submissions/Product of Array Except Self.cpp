class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        //O(n) Time and O(n) Space where n->size of input array
        int zeroes=0;
        for(auto z:nums)
        {
            if(z==0)
                zeroes++;

            if(zeroes>1)
                break;
        }

        if(zeroes>1)
        {
            vector<int> zero(nums.size(), 0);
            return zero;
        }

        vector<int> left(nums.size());
        vector<int> right(nums.size());

        left.at(0)=nums.at(0);
        right.at(nums.size()-1)=nums.at(nums.size()-1);

        int leftRun=left.at(0);
        for(int i=1; i<nums.size(); i++)
        {
            leftRun*=nums.at(i);
            left.at(i)=leftRun;
        }

        int rightRun=right.at(nums.size()-1);
        for(int i=nums.size()-2; i>=0; i--)
        {
            rightRun*=nums.at(i);
            right.at(i)=rightRun;
        }

        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int leftTotal;
            if(i==0)
                leftTotal=1;
            else
                leftTotal=left.at(i-1);

            int rightTotal;
            if(i==nums.size()-1)
                rightTotal=1;
            else
                rightTotal=right.at(i+1);

            ans.push_back(leftTotal*rightTotal);
        }

        return ans;


        /* O(n) Time and O(1) Space where n->size of input array
        int zeroes=0;
        for(auto z:nums)
        {
            if(z==0)
                zeroes++;

            if(zeroes>1)
                break;
        }

        if(zeroes>1)
        {
            vector<int> zero(nums.size(), 0);
            return zero;
        }

        int totalWithoutZero=1, totalWithZero=1;
        for(auto z:nums)
        {
            if(z==0)
            {
                totalWithZero*=z;
                continue;
            }

            totalWithZero*=z;
            totalWithoutZero*=z;
        }

        vector<int> ans;
        for(auto z:nums)
        {
            if(z==0)
            {
                ans.push_back(totalWithoutZero);
            }
            else
            {
                ans.push_back(totalWithZero/z);
            }
        }

        return ans;
        */
    }
};
