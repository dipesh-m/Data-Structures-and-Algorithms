class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string a, b;
        for(auto z:word1)
            a+=z;
        for(auto z:word2)
            b+=z;

        return a==b;
    }
};
