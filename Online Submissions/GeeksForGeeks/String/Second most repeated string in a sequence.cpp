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

    string arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    unordered_map<string, pair<int, int>> um;

    for(int i=0; i<n; i++)
    {
        if(um.count(arr[i])>0)
        {
            um.at(arr[i]).second++;
        }
        else
        {
            um[arr[i]]=make_pair(i, 1);
        }
    }

    priority_queue<pair<int, int>> pq;

    unordered_map<string, pair<int, int>>::iterator it=um.begin();
    for(; it!=um.end(); it++)
    {
        pq.push(make_pair(it->second.second, it->second.first));
    }

    pq.pop();

    cout<<arr[pq.top().second]<<endl;
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
