#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
typedef pair<int, int> pi;
const int mod = 1000000007;
const int MAX = 2e5;

bool checkPalindrome(string s)
{
    string orig=s;
    reverse(s.begin(), s.end());

    return orig==s?true:false;
}

void solve()
{
    string s;
    cin>>s;

    string ans="";

    for(size_t i=0; i<s.length(); i++)
    {
        for(size_t j=1; j<=s.length(); j++)
        {
            string x=s.substr(i, j);
            if(checkPalindrome(x) && x.length()>ans.length())
            {
                ans=x;
            }
        }
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
