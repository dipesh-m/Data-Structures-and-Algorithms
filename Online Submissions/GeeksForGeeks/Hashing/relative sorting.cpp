#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n, m;
    cin>>n>>m;
    int* a1=new int[n];
    int* a2=new int[m];
    for(int i=0; i<n; i++)
    {
        cin>>a1[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>a2[i];
    }

    map<int, int> um;
    for(int i=0; i<n; i++)
    {
        if(um.count(a1[i])>0)
        {
            um.at(a1[i])++;
        }
        else
        {
            um[a1[i]]=1;
        }
    }

    for(int i=0; i<m; i++)
    {
        if(um.count(a2[i])>0)
        {
            map<int, int>::iterator it=um.find(a2[i]);
            int c=it->second;
            for(int j=0; j<c; j++)
            {
                cout<<it->first<<" ";
            }
            um.erase(a2[i]);
        }
    }

    map<int, int>::iterator it=um.begin();
    for(; it!=um.end(); it++)
    {
        int c=it->second;
        for(int j=0; j<c; j++)
        {
            cout<<it->first<<" ";
        }
    }

    cout<<endl;

    delete []a1;
    delete []a2;
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
