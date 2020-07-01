#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    if(s=="")
    {
        cout<<"-1"<<endl;
        return;
    }

    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i]=='1')
        {
            cout<<i<<endl;
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
