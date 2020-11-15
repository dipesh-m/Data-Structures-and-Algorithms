#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    int i=s.length()-1;
    while(i>=0)
    {
        while(s[i]!='.')
        {
            if(i==0)
            {
                i--;
                break;
            }
            i--;
        }
        int j=i+1;
        while(s[j]!='.')
        {
            if(j==s.length())
            {
                break;
            }

            cout<<s[j];
            j++;
        }

        if(i>=0)
        {
            cout<<s[i];
        }
        i--;
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
