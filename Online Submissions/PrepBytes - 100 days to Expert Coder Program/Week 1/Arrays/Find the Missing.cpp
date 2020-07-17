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
    bool* present=new bool[n];
    memset(present, 0, sizeof(present));
    for(int i=1; i<n; i++)
    {
        int x;
        cin>>x;
        present[x]=1;
    }

    for(int i=1; i<n; i++)
    {
        if(!present[i])
        {
            cout<<i<<endl;
            return;
        }
    }

    cout<<n<<endl;

    delete []present;
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
