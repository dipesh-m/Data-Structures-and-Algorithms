class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        if(s.size()<11)
            return ans;

        unordered_map<string, int> um;
        int i=0;
        string temp;
        while(i<s.size())
        {
            temp=s.substr(i,10);
            if(++um[temp] == 2)
                ans.push_back(temp);
            i++;
        }

        return ans;
    }
};
