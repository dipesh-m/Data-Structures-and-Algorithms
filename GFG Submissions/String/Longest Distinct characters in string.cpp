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

    unordered_map<char, int> um;

    int ans=0;

    int i=0;
    while(i<s.length())
    {
        int sum=0;

        while(um.count(s[i])==0 && i<s.length())
        {
            um.insert(make_pair(s[i], i));
            sum++;
            i++;
        }

        ans=max(ans, sum);

        if(i>=s.length())
        {
            break;
        }

        i=um.at(s[i])+1;

        um.clear();
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
