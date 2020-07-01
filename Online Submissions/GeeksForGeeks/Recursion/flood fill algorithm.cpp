#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void print(int** arr, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
}

void start(int** arr, int n, int m, int x, int y, int k, int rep)
{
    arr[x][y]=k;
    if(x!=0 && arr[x-1][y]==rep)
    {
        start(arr, n, m, x-1, y, k, rep);
    }
    if(x!=n-1 && arr[x+1][y]==rep)
    {
        start(arr, n, m, x+1, y, k, rep);
    }
    if(y!=0 && arr[x][y-1]==rep)
    {
        start(arr, n, m, x, y-1, k, rep);
    }
    if(y!=m-1 && arr[x][y+1]==rep)
    {
        start(arr, n, m, x, y+1, k, rep);
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int** arr=new int*[n];
    for(int i=0 ;i<n; i++)
    {
        arr[i]=new int[m];
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    int x, y, k;
    cin>>x>>y>>k;
    int rep=arr[x][y];

    start(arr, n, m, x, y, k, rep);
    print(arr, n, m);
    cout<<endl;

    for(int i=0; i<n; i++)
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
