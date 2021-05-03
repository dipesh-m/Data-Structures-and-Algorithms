class Solution {
public:
    string removeDuplicates(string S)
    {
        string ans;
        for(auto& z:S)
        {
            if(ans.size()>0 && z==ans.at(ans.size()-1))
                ans.pop_back();
            else
                ans+=z;
        }

        return ans;
    }
};
