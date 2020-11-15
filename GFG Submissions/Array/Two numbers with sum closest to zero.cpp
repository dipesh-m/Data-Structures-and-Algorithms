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

    int* arr=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);
    int ans, im=INT_MAX;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(abs(arr[i]+arr[j])<im)
            {
                im=abs(arr[i]+arr[j]);
                ans=arr[i]+arr[j];
            }
        }
    }

    cout<<ans<<endl;

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
