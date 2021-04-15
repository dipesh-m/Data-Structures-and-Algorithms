class Solution {
public:
    string toLowerCase(string str)
    {
        for(int i=0; i<str.size(); i++)
        {
            if(str.at(i)>='A' && str.at(i)<='Z')
            {
                str[i]+=('a'-'A');
            }
        }

        return str;
    }
};
