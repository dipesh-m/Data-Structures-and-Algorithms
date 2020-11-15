#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n, m, x;
    cin>>n>>m>>x;

    int* arr1=new int[n];
    int* arr2=new int[m];
    for(int i=0; i<n; i++)
    {
        cin>>arr1[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>arr2[i];
    }

    sort(arr1, arr1+n);

    unordered_set<int> us;
    for(int i=0; i<m; i++)
    {
        us.insert(arr2[i]);
    }

    bool something=false;
    bool first=true;
    for(int i=0; i<n; i++)
    {
        if(us.count(x-arr1[i])>0)
        {
            something=true;
            if(first)
            {
                first=false;
                cout<<arr1[i]<<" "<<(x-arr1[i]);
            }
            else
            {
                cout<<','<<" "<<arr1[i]<<" "<<(x-arr1[i]);
            }
        }
    }

    if(!something)
    {
        cout<<"-1"<<endl;
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
