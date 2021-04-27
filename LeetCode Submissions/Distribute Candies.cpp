class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        unordered_set<int> us;
        for(auto z:candyType)
            us.insert(z);

        return (candyType.size()/2) < us.size() ? candyType.size()/2 : us.size();
    }
};
