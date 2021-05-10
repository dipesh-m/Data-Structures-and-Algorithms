class Solution {
public:
    string reverseWords(string s)
    {
        int i=0, j=0, next;
        while(i<s.size())
        {
            j=i;
            while(i+1<s.size() && s[i+1]!=' ')
                i++;

            next=i+2;
            while(j<i)
            {
                swap(s[i],s[j]);
                i--;
                j++;
            }

            i=next;
        }

        return s;
    }
};
