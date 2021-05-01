
bool comp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second==b.second ? a.first>b.first : a.second<b.second;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        unordered_map<int, int> um;
        for(auto& z:nums)
            um[z]++;

        vector<pair<int, int>> vec;
        for(auto& z:um)
            vec.push_back(z);

        sort(vec.begin(), vec.end(), comp);

        int i=0, j=0;
        while(i<vec.size())
        {
            for(int k=0; k<vec.at(i).second; k++)
            {
                nums[j]=vec.at(i).first;
                j++;
            }

            i++;
        }

        return nums;
    }
};
