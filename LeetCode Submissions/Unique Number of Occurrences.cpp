class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> um;
        for(auto z:arr)
            um[z]++;

        unordered_set<int> us;
        for(auto z:um)
        {
            if(us.count(z.second)>0)
                return false;

            us.insert(z.second);
        }

        return true;
    }
};
