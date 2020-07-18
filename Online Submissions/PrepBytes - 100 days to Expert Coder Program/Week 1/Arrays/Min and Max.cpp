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

    int min=INT_MAX, max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<min)
        {
            min=arr[i];
        }

        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    cout<<min<<" "<<max<<endl;
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
