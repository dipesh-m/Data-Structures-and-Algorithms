class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max=*max_element(candies.begin(), candies.end());

        vector<bool> ans;
        for(int i=0; i<candies.size(); i++)
        {
            if(candies.at(i)+extraCandies>=max)
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
        }

        return ans;
    }
};
