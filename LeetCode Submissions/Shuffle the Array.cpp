class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j=n, i=1;

        while(j<nums.size())
        {
            nums.insert(nums.begin()+i, nums.at(j));
            j+=2;
            i+=2;
        }

        for(int i=0; i<n; i++)
        {
            nums.pop_back();
        }

        return nums;
    }
};
