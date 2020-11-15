#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int m,n;
    cin>>m>>n;

    string s, t;
    cin>>s>>t;

    int dp[m+1][n+1];
    for(int i=0; i<n+1; i++)
    {
        dp[0][i]=i;
    }
    for(int i=0; i<m+1; i++)
    {
        dp[i][0]=i;
    }

    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(s[m-i]==t[n-j])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
            }
        }
    }

    cout<<dp[m][n]<<endl;
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
