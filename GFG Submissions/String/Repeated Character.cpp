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

    int n=s.length();

    unordered_map<char, pair<int, int>> um;

    for(int i=0; i<n; i++)
    {
        if(um.count(s[i])>0)
        {
            um.at(s[i]).second++;
        }
        else
        {
            um[s[i]]=make_pair(i, 1);
        }
    }

    int lowest=INT_MAX;
    unordered_map<char, pair<int, int>>::iterator it=um.begin();
    for(; it!=um.end(); it++)
    {
        if(it->second.second>1 && it->second.first<lowest)
        {
            lowest=it->second.first;
        }
    }

    if(lowest==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<s[lowest]<<endl;
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
