#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int N, W;
    cin>>N>>W;

    int* values=new int[N];
    int* weights=new int[N];
    for(int i=0; i<N; i++)
    {
        cin>>values[i];
    }
    for(int i=0; i<N; i++)
    {
        cin>>weights[i];
    }

    int** dp=new int*[N+1];
    for(int i=0; i<N+1; i++)
    {
        dp[i]=new int[W+1];
    }

    for(int i=0; i<W+1; i++)
    {
        dp[0][i]=0;
    }
    for(int i=0; i<N+1; i++)
    {
        dp[i][0]=0;
    }

    for(int i=1; i<N+1; i++)
    {
        for(int j=1; j<W+1; j++)
        {
            int x=INT_MIN;
            if(weights[N-i]<=j)
            {
                x=values[N-i] + dp[i-1][j-weights[N-i]];
            }

            int y=dp[i-1][j];

            dp[i][j]=max(x, y);
        }
    }

    cout<<dp[N][W]<<endl;

    delete []values;
    delete []weights;
    for(int i=0; i<N+1; i++)
    {
        delete []dp[i];
    }
    delete []dp;
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
