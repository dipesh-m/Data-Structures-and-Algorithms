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

    int count=1, major=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]==major)
        {
            count++;
        }
        else
        {
            count--;
        }

        if(count==0)
        {
            major=arr[i];
            count=1;
        }
    }

    count=0;
    for(int i=0; i<n ;i++)
    {
        if(arr[i]==major)
        {
            count++;
        }
    }

    if(count>(n/2))
    {
        cout<<major<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
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
