#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

int getValue(char a)
{
    if(a=='I')
    {
        return 1;
    }
    if(a=='V')
    {
        return 5;
    }
    if(a=='X')
    {
        return 10;
    }
    if(a=='L')
    {
        return 50;
    }
    if(a=='C')
    {
        return 100;
    }
    if(a=='D')
    {
        return 500;
    }
    if(a=='M')
    {
        return 1000;
    }
}

void solve()
{
    string s;
    cin>>s;

    int i=0, ans=0;
    while(i<s.length())
    {
        int a=getValue(s[i]);
        ans+=a;
        if(i!=0)
        {
            int b=getValue(s[i-1]);
            if(b<a)
            {
                ans-=(2*b);
            }
        }

        i++;
    }

    cout<<ans<<endl;
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
