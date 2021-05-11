class Solution {
public:
    bool detectCapitalUse(string word)
    {
        int sc=0;
        for(auto& z:word)
        {
            if(z>='a')
                sc++;
        }

        if(sc==word.size() || sc==0 || (word[0]<='Z' && sc==word.size()-1))
            return true;

        return false;
    }
};
