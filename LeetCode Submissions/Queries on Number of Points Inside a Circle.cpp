class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> ans;
        for(auto& z:queries)
        {
            int c=0;
            for(auto& k:points)
            {
                if(sqrt((pow(abs(z.at(0)-k.at(0)),2))+(pow(abs(z.at(1)-k.at(1)),2))) <= z.at(2))
                    c++;
            }

            ans.push_back(c);
        }

        return ans;
    }
};
