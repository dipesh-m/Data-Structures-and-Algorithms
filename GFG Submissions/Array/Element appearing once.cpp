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

    unordered_map<int, int> um;
    for(int i=0; i<n; i++)
    {
        if(um.count(arr[i])>0)
        {
            um.at(arr[i])++;
        }
        else
        {
            um[arr[i]]=1;
        }
    }

    for(auto it=um.begin(); it!=um.end(); it++)
    {
        if(it->second==1)
        {
            cout<<it->first<<endl;
            return;
        }
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
