class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int i=0;
        for(int j=0; j<nums.size(); j++)
        {
            if(nums.at(j)<=0)
            {
                swap(nums.at(i), nums.at(j));
                i++;
            }
        }

        int start=i;
        int size=nums.size()-start;

        while(i<nums.size())
        {
            if(start+(long long)abs(nums.at(i))-1 < nums.size() && nums.at(start+abs(nums.at(i))-1)>0)
            {
                nums.at(start+abs(nums.at(i))-1)=-nums.at(start+abs(nums.at(i))-1);
            }

            i++;
        }

        int ans=1;
        for(int k=start; k<nums.size(); k++)
        {
            if(nums.at(k)<0)
                ans++;
            else
                return ans;
        }

        return size+1;
    }
};
