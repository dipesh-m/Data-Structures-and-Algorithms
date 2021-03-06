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

    int freq[26]={0};
    for(int i=0; i<a.length(); i++)
    {
        freq[a[i]-'a']++;
    }

    for(int i=0; i<b.length(); i++)
    {
        freq[b[i]-'a']--;
    }

    for(int i=0; i<26; i++)
    {
        if(freq[i]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
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
