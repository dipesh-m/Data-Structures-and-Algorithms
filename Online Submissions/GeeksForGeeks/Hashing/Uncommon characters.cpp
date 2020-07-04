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

    int arr[26]={0};
    for(int i=0; i<a.length(); i++)
    {
        arr[a[i]-'a']=1;
    }

    for(int i=0; i<b.length(); i++)
    {
        if(arr[b[i]-'a']==1 || arr[b[i]-'a']==-1)
        {
            arr[b[i]-'a']=-1;
        }
        else
        {
            arr[b[i]-'a']=2;
        }
    }

    for(int i=0; i<26; i++)
    {
        if(arr[i]==1 || arr[i]==2)
        {
            cout<<(char)(i+'a');
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
