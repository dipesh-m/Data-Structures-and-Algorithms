#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int m, n;
    cin>>m>>n;
    int arr1[m][n];
    int arr2[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr1[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr2[i][j];
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr1[i][j]+arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int ans=0;
            for(int k=0; k<m; k++)
            {
                ans+=arr1[i][k]*arr2[k][j];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
