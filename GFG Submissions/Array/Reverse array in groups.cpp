#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void reverseArr(int* arr, int si, int ei)
{
    int i=si, j=ei;
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

        i++;
        j--;
    }
}

void solve()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int i=0;
    while(i<n)
    {
        if((i+k-1)<n)
        {
            reverseArr(arr, i, i+k-1);
        }
        else
        {
            reverseArr(arr, i, n-1);
        }

        i=i+k;
    }

    for(int i=0; i<n; i++)
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
