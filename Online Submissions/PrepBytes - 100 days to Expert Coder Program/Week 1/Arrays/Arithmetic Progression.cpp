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
    map<int, vector<int>> m;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;

        if(m.count(x)>0)
        {
            m.at(x).push_back(i);
        }
        else
        {
            vector<int> v;
            v.push_back(i);
            m[x]=v;
        }
    }

    for(int j=0; j<=1; j++)
    {
        int count=0;

        for(auto it=m.begin(); it!=m.end(); it++)
        {
            if(it->second.size()==1)
            {
                if(j==0)
                {
                    count++;
                }
                else
                {
                    cout<<it->first<<" "<<"0"<<endl;
                }
            }
            else
            {
                bool toPrint=true;
                int x=it->second.at(1)-it->second.at(0);
                for(int i=1; i<it->second.size(); i++)
                {
                    if((it->second.at(i)-it->second.at(i-1))!=x)
                    {
                        toPrint=false;
                        break;
                    }
                }

                if(toPrint)
                {
                    if(j==0)
                    {
                        count++;
                    }
                    else
                    {
                        cout<<it->first<<" "<<x<<endl;
                    }
                }
            }
        }

        if(j==0)
        {
            cout<<count<<endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
