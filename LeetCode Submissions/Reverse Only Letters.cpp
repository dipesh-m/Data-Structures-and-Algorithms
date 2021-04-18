class Solution {
public:
    string reverseOnlyLetters(string s)
    {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            if(s.at(i)<'A' || s.at(i)>'z' || (s.at(i)>'Z' && s.at(i)<'a'))
                i++;
            else if(s.at(j)<'A' || s.at(j)>'z' || (s.at(j)>'Z' && s.at(j)<'a'))
                j--;
            else
            {
                swap(s.at(i), s.at(j));
                i++;
                j--;
            }
        }

        return s;
    }
};
