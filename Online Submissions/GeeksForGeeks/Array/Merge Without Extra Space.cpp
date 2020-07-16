#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

int nextGap(int gap)
{
    if(gap<=1)
    {
        return 0;
    }

    return (gap/2)+(gap%2);
}

void solve()
{
    int n1, n2;
    cin>>n1>>n2;
    int* arr1=new int[n1];
    for(int i=0; i<n1; i++)
    {
        cin>>arr1[i];
    }
    int* arr2=new int[n2];
    for(int i=0; i<n2; i++)
    {
        cin>>arr2[i];
    }

    int i, j, gap=n1+n2;
    for(gap=nextGap(gap); gap>0; gap=nextGap(gap))
    {
        for(i=0; i+gap<n1; i++)
        {
            if(arr1[i+gap]<arr1[i])
            {
                swap(arr1[i+gap], arr1[i]);
            }
        }

        for(j=gap>n1?gap-n1:0; i<n1&&j<n2; i++, j++)
        {
            if(arr2[j]<arr1[i])
            {
                swap(arr1[i], arr2[j]);
            }
        }

        if(j<n2)
        {
            for(j=0; j+gap<n2; j++)
            {
                if(arr2[j+gap]<arr2[j])
                {
                    swap(arr2[j+gap], arr2[j]);
                }
            }
        }
    }

    for(int k=0; k<n1; k++)
    {
        cout<<arr1[k]<<" ";
    }

    for(int k=0; k<n2; k++)
    {
        cout<<arr2[k]<<" ";
    }

    cout<<endl;

    delete []arr1;
    delete []arr2;
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
