#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int d;
    cin>>d;
    int denom[d];
    for(int i=0; i<d; i++)
    {
        cin>>denom[i];
    }
    int sum;
    cin>>sum;

    int dp[sum+1]={0};
    dp[0]=1;

    for(int i=0; i<d; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(denom[i]<=j)
            {
                dp[j]+=dp[j-denom[i]];
            }
        }
    }

    cout<<dp[sum]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cases
    {
        solve();
    }

    return 0;
}
