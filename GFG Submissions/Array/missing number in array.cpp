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
    bool there[n+1]={0};
    int x;
    for(int i=1; i<n; i++)
    {
        cin>>x;
        there[x]=true;
    }

    for(int i=1; i<n+1; i++)
    {
        if(!there[i])
        {
            cout<<i<<endl;
            break;
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
