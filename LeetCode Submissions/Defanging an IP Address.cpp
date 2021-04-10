class Solution {
public:
    string defangIPaddr(string address) {
        string ans;

        for(int i=0; i<address.size(); i++)
        {
            if(address.at(i)=='.')
            {
                ans+="[.]";
            }
            else
            {
                ans+=address.at(i);
            }
        }

        return ans;
    }
};
