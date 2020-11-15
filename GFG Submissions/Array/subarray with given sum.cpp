#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n, s;
    cin>>n>>s;
    int* arr=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int sum=0, j=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum+arr[i]>s)
        {
            while(sum>s)
            {
                sum-=arr[j];
                j++;
            }
        }

        if(sum==s)
        {
            cout<<j+1<<" "<<i+1<<endl;
            delete arr;
            return;
        }
    }
    cout<<"-1"<<endl;
    delete arr;
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
