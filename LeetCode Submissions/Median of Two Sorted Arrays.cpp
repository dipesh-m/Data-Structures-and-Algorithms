class Solution {
public:
    double helper(vector<int>& nums1, int si1, int ei1, vector<int>& nums2, int si2, int ei2)
    {
        vector<int> output;
        int i=si1, j=si2;

        while(i<=ei1 && j<=ei2)
        {
            if(nums1.at(i)<=nums2.at(j))
            {
                output.push_back(nums1.at(i));
                i++;
            }
            else
            {
                output.push_back(nums2.at(j));
                j++;
            }
        }

        while(i<=ei1)
        {
            output.push_back(nums1.at(i));
            i++;
        }

        while(j<=ei2)
        {
            output.push_back(nums2.at(j));
            j++;
        }

        double ans;
        int mid=output.size()/2;
        if(output.size()%2==0)
        {
            ans=(double)((double)output.at(mid-1)+(double)output.at(mid))/2;
        }
        else
        {
            ans=(double)(output.at(mid));
        }

        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        return helper(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
    }
};
