#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
typedef pair<int, int> pi;
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

    int ans=arr[0];
    int sum=arr[0];

    for(int i=1; i<n; i++)
    {
        sum=max(arr[i], sum+arr[i]);
        ans=max(ans, sum);
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
