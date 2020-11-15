#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void rev(int* arr, int l, int r)
{
    int i=l, j=r;
    while(i<j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int d;
    cin>>d;

    rev(arr, 0, d-1);
    rev(arr, d, n-1);
    rev(arr, 0, n-1);

    for(int i=0; i<n ;i++)
    {
        cout<<arr[i]<<" ";
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
