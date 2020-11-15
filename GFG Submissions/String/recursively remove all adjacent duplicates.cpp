#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
typedef pair<int, int> pi;
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    while(1)
    {
        bool go=false;
        int i=0, j=1;
        while(j<s.length())
        {
            if(s[i]==s[i+1])
            {
                go=true;
                break;
            }
            i++;
            j++;
        }

        if(go)
        {
            int i=0, j=1;
            while(j<s.length())
            {
                if(s[i]==s[j])
                {
                    int x=j;
                    while(s[x]==s[j])
                    {
                        x++;
                    }
                    s=s.substr(0, i)+s.substr(x, s.length()-x);

                    i=(x)-(x-i);
                    j=i+1;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }
        else
        {
            break;
        }
    }

    cout<<s<<endl;
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
