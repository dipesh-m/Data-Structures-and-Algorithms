


//O(n) solution



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

    ll* left=new ll[n];
    ll* right=new ll[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    int ans=0;

    for(int i=1; i<n; i++)
    {
        left[i]=max(left[i-1], arr[i]);
    }

    for(int i=n-2; i>=0; i--)
    {
        right[i]=max(right[i+1], arr[i]);
    }

    for(int i=1; i<n-1; i++)
    {
        ans+=min(left[i], right[i])-arr[i];
    }

    cout<<ans<<endl;

    delete []arr;
    delete []left;
    delete []right;
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



/*O(n^2) solution



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
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int ans=0, lmax=arr[0], rmax=arr[n-1];
    for(int i=1; i<n-1; i++)
    {
        for(int j=i; j>=0; j--)
        {
            lmax=max(lmax, arr[j]);
        }

        for(int j=i; j<n; j++)
        {
            rmax=max(rmax, arr[j]);
        }

        ans+=min(lmax, rmax)-arr[i];
    }

    cout<<ans<<endl;
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
*/
