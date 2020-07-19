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

    string s;
    cin>>s;

    int arr[26]={0};
    for(int i=0; i<n; i++)
    {
        arr[s[i]-'a']++;
    }

    for(int i=0; i<n; i++)
    {
        if(arr[s[i]-'a']==1)
        {
            cout<<s[i]<<endl;
            return;
        }
    }

    cout<<"-1"<<endl;
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
