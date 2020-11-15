#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string a, b, c;
    cin>>a>>b;

    unordered_set<char> us1;
    for(int i=0; i<a.length(); i++)
    {
        if(us1.count(a[i])==0)
        {
            us1.insert(a[i]);
        }
    }

    unordered_set<char> us2;
    for(int i=0; i<b.length(); i++)
    {
        if(us2.count(b[i])==0)
        {
            us2.insert(b[i]);
        }
    }

    for(int i=0; i<a.length(); i++)
    {
        if(us1.count(a[i])>0 && us2.count(a[i])>0)
        {
            continue;
        }
        else
        {
            c+=a[i];
        }
    }

    for(int i=0; i<b.length(); i++)
    {
        if(us1.count(b[i])>0 && us2.count(b[i])>0)
        {
            continue;
        }
        else
        {
            c+=b[i];
        }
    }

    if(c!="")
    {
        cout<<c<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
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
