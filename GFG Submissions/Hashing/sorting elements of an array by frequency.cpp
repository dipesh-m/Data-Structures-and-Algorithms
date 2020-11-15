#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
typedef pair<int, int> pi;
const int mod = 1000000007;
const int MAX = 2e5;

bool comp(pi p1, pi p2)
{
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }

    return p1.second>p2.second;
}

void solve()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        if(m.count(arr[i])>0)
        {
            m.at(arr[i])++;
        }
        else
        {
            m[arr[i]]=1;
        }
    }

    vector<pi> v;

    unordered_map<int, int>::iterator it=m.begin();
    for(; it!=m.end(); it++)
    {
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), comp);

    for(vector<pi>::size_type i=0; i<v.size(); i++)
    {
        int x=v[i].second;
        for(int j=0; j<x; j++)
        {
            cout<<v[i].first<<" ";
        }
    }

    cout<<endl;
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
