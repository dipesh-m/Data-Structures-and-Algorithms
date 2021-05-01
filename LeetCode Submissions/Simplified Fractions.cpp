class Solution {
public:
    int gcd(int x, int y)
    {
        int i=min(x,y);
        while(i>=1)
        {
            if(x%i==0 && y%i==0)
                break;

            i--;
        }

        return i;
    }

    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for(int i=1; i<=n-1; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(i==1 || gcd(i,j)==1)
                    ans.push_back(""+to_string(i)+'/'+to_string(j));
            }
        }

        return ans;
    }
};
