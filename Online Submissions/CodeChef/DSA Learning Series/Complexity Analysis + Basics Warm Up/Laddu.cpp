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
    string origin;
    cin>>origin;

    int laddus=0;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s=="TOP_CONTRIBUTOR")
        {
            laddus+=300;
        }
        else if(s=="CONTEST_HOSTED")
        {
            laddus+=50;
        }
        else if(s=="CONTEST_WON")
        {
            laddus+=300;

            int x;
            cin>>x;

            if(x<=20)
            {
                laddus+=(20-x);
            }

        }
        else if(s=="BUG_FOUND")
        {
            int x;
            cin>>x;

            laddus+=x;
        }
    }

    if(origin=="INDIAN")
    {
        cout<<(laddus/200)<<endl;
    }
    else
    {
        cout<<(laddus/400)<<endl;
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
