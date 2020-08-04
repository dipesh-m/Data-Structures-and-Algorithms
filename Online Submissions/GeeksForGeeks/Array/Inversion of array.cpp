#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void merge2SortedArrays(int a[], int si, int ei, ll& ans)
{
    int size_output=(ei-si)+1;
    int* output=new int[size_output];

    int mid=(si+ei)/2;
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei)
    {
        if(a[i]<=a[j])
        {
            output[k]=a[i];
            i++;
            k++;
        }
        else
        {
            ans+=(mid+1)-i;

            output[k]=a[j];
            j++;
            k++;
        }

    }
    while(i<=mid)
    {
        output[k]=a[i];
        i++;
        k++;
    }
    while(j<=ei)
    {
        output[k]=a[j];
        j++;
        k++;
    }
    int x=0;
    for(int l=si; l<=ei; l++)
    {
        a[l]=output[x];
        x++;
    }
    delete []output;
}

void mergeSort(int a[], int si, int ei, ll& ans)
{
    if(si>=ei)
    {
        return;
    }

    int mid=(si+ei)/2;

    mergeSort(a, si, mid, ans);
    mergeSort(a, mid+1, ei, ans);

    merge2SortedArrays(a, si, ei, ans);
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

    ll ans=0;
    mergeSort(arr, 0, n-1, ans);

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
