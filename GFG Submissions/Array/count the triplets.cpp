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
    int ans=0;

    unordered_map<int, bool> um;
    for(int i=0; i<n; i++)
    {
        if(um.count(arr[i])>0)
        {
            um.at(arr[i])=true;
        }
        else
        {
            um[arr[i]]=true;
        }
    }

    for(int i=0; i<n-1; i++)
    {
        int count=0;
        for(int j=i+1; j<n; j++)
        {
            int x=arr[i]+arr[j];
            if(um.count(x)>0)
            {
                count++;
            }
        }
        ans+=count;
    }

    if(ans>0)
        cout<<ans<<endl;
    else
        cout<<"-1"<<endl;

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
