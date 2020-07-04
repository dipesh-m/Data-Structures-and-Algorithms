#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    getline(cin, s);

    unordered_set<char> us;

    int i=0;
    while(i<s.length())
    {
        if(us.count(s[i])==0)
        {
            us.insert(s[i]);
            i++;
        }
        else
        {
            if(i!=s.length()-1)
            {
                s=s.substr(0, i)+s.substr(i+1, (s.length())-(i+1));
            }
            else
            {
                s=s.substr(0, i);
            }
        }
    }

    cout<<s<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    for(int i=1; i<=t; i++)
    {
        solve();
    }

    return 0;
}
