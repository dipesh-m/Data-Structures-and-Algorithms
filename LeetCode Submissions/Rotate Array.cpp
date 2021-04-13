class Solution {
public:
    void reverse(vector<int>& nums, int si, int ei)
    {
        while(si<ei)
        {
            swap(nums.at(si), nums.at(ei));
            si++;
            ei--;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        int n=nums.size();
        k=k%n;

        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};
