#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string a, b;
    cin>>a>>b;

    string temp=a;

    a=a.substr(2, a.length()-2)+a.substr(0, 2);
    if(a==b)
    {
        cout<<"1"<<endl;
    }
    else
    {
        temp=temp.substr(temp.length()-2, 2)+temp.substr(0, temp.length()-2);
        if(temp==b)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
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
