class Solution {
public:
    int compress(vector<char>& chars)
    {
        int pos=0, i=0, sz;
        char symb;
        while(i<chars.size())
        {
            sz=1;
            symb=chars[i];
            while(i+1<chars.size() && chars[i+1]==symb)
            {
                i++;
                sz++;
            }

            chars[pos]=symb;
            pos++;
            if(sz>1)
            {
                string x=to_string(sz);
                for(auto& z:x)
                {
                    chars[pos]=z;
                    pos++;
                }
            }

            i++;
        }

        return pos;
    }
};
