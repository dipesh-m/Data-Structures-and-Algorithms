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

    int smallestLength=INT_MAX;
    string smallestString;
    string* arr=new string[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i].length()<smallestLength)
        {
            smallestLength=arr[i].length();
            smallestString=arr[i];
        }
    }

    string ans="";
    bool b=false;
    for(int i=0; i<smallestLength; i++)
    {
        if(b)
        {
            break;
        }

        bool take=true;
        for(int j=0; j<n; j++)
        {
            if(arr[j].at(i)!=smallestString[i])
            {
                take=false;
                b=true;
                break;
            }
        }

        if(take)
        {
            ans+=smallestString[i];
        }
    }

    if(ans.length()!=0)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }

    delete []arr;
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
