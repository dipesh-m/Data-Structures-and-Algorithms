class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int i=1, j=0;
        while(i<word1.size() && j<word2.size())
        {
            word1.insert(i, word2.substr(j, 1));
            i+=2;
            j++;
        }

        while(j<word2.size())
        {
            word1+=word2.at(j);
            j++;
        }

        return word1;
    }
};
