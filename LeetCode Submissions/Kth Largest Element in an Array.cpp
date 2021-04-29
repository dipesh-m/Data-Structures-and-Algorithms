//QuickSelect - O(n) average and O(n^2) worst case time and O(1) space ignoring recursion stack
class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi, int pivot)
    {
        int i=lo, j=lo;
        while(i<=hi)
        {
            if(nums[i]>=pivot)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return j-1;
    }

    int quickSelect(vector<int>& nums, int lo, int hi, int k)
    {
        int pivot=nums[hi];
        int pi=partition(nums, lo, hi, pivot);

        if(pi>k)
        {
            return quickSelect(nums, lo, pi-1, k);
        }
        else if(pi<k)
        {
            return quickSelect(nums, pi+1, hi, k);
        }

        return pivot;
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        return quickSelect(nums, 0, nums.size()-1, k-1);
    }
};

//O(nlogn) time and O(1) space

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums.at(k-1);
    }
};

//O(n) time and O(k) space

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto z:nums)
        {
            pq.push(z);
            if(pq.size()>k)
                pq.pop();
        }

        return pq.top();
    }
};
