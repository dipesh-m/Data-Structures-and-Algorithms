#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

int start(int** arr, int m, int n, int i, int j)
{
    if(i==m-1 && j==n-1)
    {
        return 1;
    }

    int ans=0;
    if(j!=n-1)
        ans+=start(arr, m, n, i, j+1);
    if(i!=m-1)
        ans+=start(arr, m, n, i+1, j);

    return ans;
}

void solve()
{
    int m, n;
    cin>>m>>n;

    int** arr=new int*[m];
    for(int i=0 ;i<m; i++)
    {
        arr[i]=new int[n];
    }

    cout<<start(arr, m, n, 0, 0)<<endl;
    for(int i=0; i<m; i++)
    {
        delete []arr[i];
    }
    delete []arr;
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
