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
    ll* arr=new ll[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    ll maxEle=arr[n-1]+1;
    int maxi=n-1;
    int mini=0;

    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            arr[i]=arr[i]+(arr[maxi]%maxEle)*maxEle;
            maxi--;
        }
        else
        {
            arr[i]=arr[i]+(arr[mini]%maxEle)*maxEle;
            mini++;
        }
    }

    for(int i=0; i<n; i++)
    {
        arr[i]=arr[i]/maxEle;
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    delete[]arr;
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
