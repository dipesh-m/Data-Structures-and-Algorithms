#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s1, s2;
    cin>>s1>>s2;

    if(s1.size()!=s2.size())
    {
        cout<<"0"<<endl;
        return;
    }

    string im=s1+s1;
    if(im.find(s2)==string::npos)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"1"<<endl;
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
