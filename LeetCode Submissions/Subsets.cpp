class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int>& im, vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(im);
            return;
        }

        im.push_back(nums.at(i));
        helper(nums, i+1, im, ans);
        im.pop_back();
        helper(nums, i+1, im, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> im;

        helper(nums, 0, im, ans);
        return ans;
    }
};
