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
    int* arr=new int[n];
    int* ans=new int[n];
    for(int i=0; i<n; i++)
    {
        ans[i]=INT_MIN;
        cin>>arr[i];
    }

    int j=0;
    int largest=arr[n-1];
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]>=largest)
        {
            ans[j]=arr[i];
            largest=arr[i];
            j++;
        }
    }

    for(int i=j-1; i>=0; i--)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;

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
