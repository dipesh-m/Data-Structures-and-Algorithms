class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> um;

        for(int i=0; i<nums.size(); i++)
        {
            if(um.count(nums.at(i))>0)
            {
                um.at(nums.at(i)).push_back(i);
            }
            else
            {
                vector<int> im;
                im.push_back(i);
                um[nums.at(i)]=im;
            }
        }

        int ans=0;
        for(auto it=um.begin(); it!=um.end(); it++)
        {
            int currSize=it->second.size();
            while(currSize>1)
            {
                ans+=(currSize-1);
                currSize--;
            }
        }

        return ans;
    }
};
