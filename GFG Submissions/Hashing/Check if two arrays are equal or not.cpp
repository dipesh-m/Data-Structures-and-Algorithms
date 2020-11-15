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

    ll arr1[n], arr2[n];
    for(ll i=0; i<n; i++)
    {
        cin>>arr1[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin>>arr2[i];
    }

    unordered_map<ll, ll> um;
    for(ll i=0; i<n; i++)
    {
        if(um.count(arr1[i])>0)
        {
            um.at(arr1[i])++;
        }
        else
        {
            um[arr1[i]]=1;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(um.count(arr2[i])>0)
        {
            um.at(arr2[i])--;
        }
        else
        {
            cout<<"0"<<endl;
            return;
        }

        if(um.at(arr2[i])==0)
        {
            um.erase(arr2[i]);
        }
    }

    if(um.size()==0)
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
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
