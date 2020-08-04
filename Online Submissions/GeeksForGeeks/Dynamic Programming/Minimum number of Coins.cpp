#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int denom[10]={1,2,5,10,20,50,100,200,500,2000};
    int sum;
    cin>>sum;

    sort(denom, denom+10);

    vector<int> ans;
    for(int i=9; i>=0; i--)
    {
        while(denom[i]<=sum)
        {
            sum-=denom[i];
            ans.push_back(denom[i]);
        }
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans.at(i)<<" ";
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
