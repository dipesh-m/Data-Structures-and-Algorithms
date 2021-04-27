
//O(nlogn) time and O(1) space

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1.at(i)==nums2.at(j))
            {
                ans.push_back(nums1.at(i));

                i++;
                while(i<nums1.size() && nums1.at(i-1)==nums1.at(i))
                    i++;

                j++;
                while(j<nums2.size() && nums2.at(j-1)==nums2.at(j))
                    j++;
            }
            else if(nums1.at(i)<nums2.at(j))
            {
                i++;
                while(i<nums1.size() && nums1.at(i-1)==nums1.at(i))
                    i++;
            }
            else
            {
                j++;
                while(j<nums2.size() && nums2.at(j-1)==nums2.at(j))
                    j++;
            }
        }

        return ans;
    }
};

//O(n) time and O(n) space

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_set<int> us;

        for(auto z:nums1)
            us.insert(z);

        for(auto z:nums2)
        {
            if(us.count(z)>0)
            {
                ans.push_back(z);
                us.erase(z);
            }
        }

        return ans;
    }
};
