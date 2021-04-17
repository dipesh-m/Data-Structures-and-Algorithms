class Solution {
public:
    string generateTheString(int n)
    {
        string ans;
        if(n%2==0)
        {
            while(n!=1)
            {
                ans+='a';
                n--;
            }

            ans+='b';
        }
        else
        {
            while(n!=0)
            {
                ans+='a';
                n--;
            }
        }

        return ans;
    }
};
