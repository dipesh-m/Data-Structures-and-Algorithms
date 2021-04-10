class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> us;
        for(int i=0; i<jewels.size(); i++)
        {
            us.insert(jewels.at(i));
        }

        int ans=0;
        for(int i=0; i<stones.size(); i++)
        {
            if(us.count(stones.at(i))>0)
            {
                ans++;
            }
        }

        return ans;
    }
};
