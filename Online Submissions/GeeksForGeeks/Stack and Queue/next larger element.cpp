#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    ll n;
    cin>>n;

    ll* arr=new ll[n];
    ll* ans=new ll[n];

    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    stack<ll> s;

    for(ll i=n-1; i>=0; i--)
    {
        while(s.size()!=0 && s.top()<arr[i])
        {
            s.pop();
        }

        if(s.size()==0)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=s.top();
        }

        s.push(arr[i]);
    }

    for(ll i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    delete []arr;
    delete []ans;
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
