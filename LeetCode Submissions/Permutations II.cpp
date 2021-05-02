class Solution {
public:
    void helper(vector<int> nums, int l, int r, vector<vector<int>>& ans)
    {
        if(l==r)
        {
            ans.push_back(nums);
            return;
        }

        for(int i=l; i<=r; i++)
        {
            if(i!=l && nums.at(i)==nums.at(l))
                continue;

            swap(nums[l], nums[i]);
            helper(nums, l+1, r, ans);

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, nums.size()-1, ans);
        return ans;
    }
};
