//ITERATIVE
class Solution {
public:
    string largestMerge(string word1, string word2)
    {
        string ans;
        while(!word1.empty() && !word2.empty())
        {
            if(word1[0]>word2[0])
            {
                ans+=word1[0];
                word1=word1.substr(1);
            }
            else if(word1[0]<word2[0])
            {
                ans+=word2[0];
                word2=word2.substr(1);
            }
            else
            {
                if(word1.substr(1)>=word2.substr(1))
                {
                    ans+=word1[0];
                    word1=word1.substr(1);
                }
                else
                {
                    ans+=word2[0];
                    word2=word2.substr(1);
                }
            }
        }

        if(!word1.empty())
            ans+=word1;

        if(!word2.empty())
            ans+=word2;

        return ans;
    }
};

//RECURSIVE
class Solution {
public:
    string largestMerge(string word1, string word2)
    {
        if(word1.size()==0 || word2.size()==0)
            return word1+word2;

        if(word1>word2)
            return word1[0]+largestMerge(word1.substr(1), word2);

        return word2[0]+largestMerge(word1, word2.substr(1));
    }
};
