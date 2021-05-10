class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_set<string> us;
        for(auto& z:paths)
            us.insert(z[0]);

        for(auto& z:paths)
        {
            if(us.find(z[1])==us.end())
                return z[1];
        }

        return "";
    }
};
