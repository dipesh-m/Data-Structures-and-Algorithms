class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        if(n<=1)
            return 0;

        int* ll=new int[n];
        int* rr=new int[n];

        ll[0]=height.at(0);
        for(int i=1; i<n; i++)
        {
            ll[i]=max(height.at(i), ll[i-1]);
        }

        rr[n-1]=height.at(n-1);
        for(int i=n-2; i>=0; i--)
        {
            rr[i]=max(height.at(i), rr[i+1]);
        }

        int output=0;
        int* ans=new int[n];
        for(int i=0; i<n; i++)
        {
            ans[i]=min(ll[i], rr[i])-height.at(i);
            output+=ans[i];
        }

        delete []ll;
        delete []rr;
        delete []ans;

        return output;
    }
};
