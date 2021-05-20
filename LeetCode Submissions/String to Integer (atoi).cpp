class Solution {
public:
    int myAtoi(string s)
    {
        long long ans=0;

        int i=0;
        while(s[i]==' ')
            i++;

        bool neg=false;
        if(s[i]=='-')
        {
            neg=true;
            i++;
        }
        else if(s[i]=='+')
            i++;
        else if(s[i]<'0' || s[i]>'9')
            return (int)ans;

        while(s[i]>='0' && s[i]<='9')
        {
            ans=ans*10+(int)(s[i]-'0');

            if(neg && (-ans)<=INT_MIN)
                return INT_MIN;

            if(!neg && ans>=INT_MAX)
                return INT_MAX;

            i++;
        }

        if(neg)
            return (int)(-ans);

        return (int)ans;
    }
};
