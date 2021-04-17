class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());

        int ans=0;
        for(int i=0, j=0; i<heights.size(); i++, j++)
        {
            if(expected.at(i)!=heights.at(i))
                ans++;
        }

        return ans;
    }
};
