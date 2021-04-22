class Solution {
public:
    string truncateSentence(string s, int k)
    {
        int spaces=0;
        for(auto z:s)
        {
            if(z==' ')
                spaces++;
        }

        int words=spaces+1;
        if(words==1 || k>=words)
            return s;

        int i=0;
        while(i<s.size())
        {
            if(k==0)
                break;

            if(s.at(i)==' ')
                k--;

            i++;
        }

        s=s.substr(0, i-1);
        return s;
    }
};
