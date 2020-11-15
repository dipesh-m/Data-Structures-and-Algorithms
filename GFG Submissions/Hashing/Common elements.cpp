#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n1, n2, n3;
    cin>>n1>>n2>>n3;

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
    int* arr3=new int[n3];
    for(int i=0; i<n3; i++)
    {
        cin>>arr3[i];
    }

    map<int, int> um;

    for(int i=0; i<n1; i++)
    {
        if(um.count(arr1[i])==0)
        {
            um[arr1[i]]=1;
        }
    }

    for(int i=0; i<n2; i++)
    {
        if(um.count(arr2[i])>0 && um.at(arr2[i])==1)
        {
            um.at(arr2[i])++;
        }
    }

    for(int i=0; i<n3; i++)
    {
        if(um.count(arr3[i])>0 && um.at(arr3[i])==2)
        {
            um.at(arr3[i])++;
        }
    }

    bool something=true;
    map<int, int>::iterator it=um.begin();
    for(; it!=um.end(); it++)
    {
        if(it->second==3)
        {
            something=false;
            cout<<it->first<<" ";
        }
    }

    if(something)
    {
        cout<<"-1";
    }

    cout<<endl;

    delete []arr1;
    delete []arr2;
    delete []arr3;
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
