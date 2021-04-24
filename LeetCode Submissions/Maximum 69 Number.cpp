class Solution {
public:
    int maximum69Number (int num)
    {
        int orig=num, add=0, mult=1;
        while(num>0)
        {
            if(num%10==6)
                add=3*mult;

            mult*=10;
            num/=10;
        }

        if(add==0)
            return orig;

        return orig+add;
    }
};
