#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int g;
    cin>>g;

    for(int x=0; x<g; x++)
    {
        int i, n, q;
        cin>>i>>n>>q;

        if(i==q)
        {
            cout<<n/2<<endl;
        }
        else
        {
            cout<<n-(n/2)<<endl;
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
