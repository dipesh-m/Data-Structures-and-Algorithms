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

    string s;
    int arr[26]={0};
    queue<char> q;
    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        s+=x;
    }

    for(int i=0; i<s.length(); i++)
    {
        q.push(s[i]);
        arr[s[i]-'a']++;

        while(!q.empty())
        {
            if(arr[q.front()-'a']>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<" ";
                break;
            }
        }

        if(q.empty())
        {
            cout<<"-1"<<" ";
        }
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
