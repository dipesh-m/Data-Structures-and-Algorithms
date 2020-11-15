#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string ip;
    cin>>ip;
    stack<char> s;
    bool ans=true;

    for(int i=0; i<ip.length(); i++)
    {
        if(i==0)
        {
            if(ip[i]==')' || ip[i]=='}' || ip[i]==']')
            {
                ans=false;
                break;
            }
        }

        if(ip[i]=='(' || ip[i]=='{' || ip[i]=='[')
        {
            s.push(ip[i]);
            continue;
        }
        else if(ip[i]==')' && !(s.empty()))
        {
            if(s.top()!='(')
            {
                ans=false;
                break;
            }
        }
        else if(ip[i]=='}' && !(s.empty()))
        {
            if(s.top()!='{')
            {
                ans=false;
                break;
            }
        }
        else if(ip[i]==']' && !(s.empty()))
        {
            if(s.top()!='[')
            {
                ans=false;
                break;
            }
        }

        if(!(s.empty()))
        {
            s.pop();
        }
    }

    if(ans && s.empty())
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"not balanced"<<endl;
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
