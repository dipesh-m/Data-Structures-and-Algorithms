class Solution {
public:
    void merge2SortedArrs(vector<int>& nums, int si, int ei, int& ans)
    {
        vector<int> output;
        int mid=(si+ei)/2;

        int i=si, j=mid+1;
        while(i<=mid && j<=ei)
        {
            if(nums.at(i)>2*(long long)nums.at(j))
            {
                ans+=(mid+1)-i;
                j++;
            }
            else
                i++;
        }

        i=si, j=mid+1;
        while(i<=mid && j<=ei)
        {
            if(nums.at(i)<=nums.at(j))
            {
                output.push_back(nums.at(i));
                i++;
            }
            else
            {
                output.push_back(nums.at(j));
                j++;
            }
        }

        while(i<=mid)
        {
            output.push_back(nums.at(i));
            i++;
        }

        while(j<=ei)
        {
            output.push_back(nums.at(j));
            j++;
        }

        int l=0;
        for(int k=si; k<=ei; k++)
        {
            nums.at(k)=output.at(l);
            l++;
        }
    }

    void mergeSort(vector<int>& nums, int si, int ei, int& ans)
    {
        if(si>=ei)
            return;

        int mid=(si+ei)/2;
        mergeSort(nums, si, mid, ans);
        mergeSort(nums, mid+1, ei, ans);

        merge2SortedArrs(nums, si, ei, ans);
    }

    int reversePairs(vector<int>& nums)
    {
        int ans=0;
        mergeSort(nums, 0, nums.size()-1, ans);
        return ans;
    }
};
