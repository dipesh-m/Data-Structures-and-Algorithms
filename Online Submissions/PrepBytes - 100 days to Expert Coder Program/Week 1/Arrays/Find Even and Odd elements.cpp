#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i]%2==0)
        {
            cout<<arr[i]<<" ";
        }
    }

    cout<<endl;

    for(int i=0; i<n; i++)
    {
        if(arr[i]%2!=0)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
