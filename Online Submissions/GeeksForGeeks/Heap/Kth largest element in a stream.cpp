#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int k, n;
    cin>>k>>n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<=k; i++)
    {
        int x;
        cin>>x;
        pq.push(x);

        if(pq.size()<k)
            cout<<"-1 ";
        else
            cout<<pq.top()<<" ";
    }

    for(int i=k+1; i<=n; i++)
    {
        int x;
        cin>>x;

        if(x>pq.top())
        {
            pq.pop();
            pq.push(x);
        }

        cout<<pq.top()<<" ";
    }

    cout<<endl;
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
