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

    int i=s.size()-1, sizeNum=0;
    while(s[i]>='0' && s[i]<='9')
    {
        sizeNum++;
        i--;
    }

    cout<<(stoi(s.substr(i+1, sizeNum))==s.size()-sizeNum)<<endl;
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
