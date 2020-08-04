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

    int freq[26]={0};
    for(int i=0; i<s.size(); i++)
    {
        freq[s[i]-'a']++;
    }

    priority_queue<pair<int, char>> pq;
    for(char i='a'; i<='z'; i++)
    {
        if(freq[i-'a']>0)
        {
            pq.push(make_pair(freq[i-'a'], i));
        }
    }

    pair<int, char> prev;
    prev.first=-1;
    prev.second='@';

    string ans;

    while(!pq.empty())
    {
        pair<int, char> k=pq.top();
        pq.pop();
        ans+=k.second;

        if(prev.first>0)
        {
            pq.push(prev);
        }

        (k.first)--;
        prev=k;
    }

    if(ans.size()!=s.size())
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
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
