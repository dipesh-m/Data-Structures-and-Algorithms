#include<iostream>
using namespace std;
#include<cmath>

int noOfBalancedBTs(int h)
{
    if(h<=1)
    {
        return 1;
    }

    int x=noOfBalancedBTs(h-1);
    int y=noOfBalancedBTs(h-2);

    int mod=(int) (pow(10, 9)) + 7;
    int ans=(int) ((((long long)(x)*x) % mod) + ((2* (long long)(x) * y) % mod)) % mod;

    return ans;
}

int noOfBalancedBTsMemHelper(int h, int* arr)
{
    if(h<=1)
    {
        return 1;
    }

    if(arr[h]!=-1)
    {
        return arr[h];
    }

    int x=noOfBalancedBTsMemHelper(h-1, arr);
    int y=noOfBalancedBTsMemHelper(h-2, arr);

    int mod=(int) (pow(10, 9)) + 7;
    int ans=(int) ((((long long)(x) * x) % mod) + ((2* (long long)(x) * y) % mod)) % mod;
    arr[h]=ans;

    return arr[h];
}

int noOfBalancedBTsMem(int h)
{
    int* arr=new int[h+1];
    for(int i=0; i<h+1; i++)
    {
        arr[i]=-1;
    }

    return noOfBalancedBTsMemHelper(h, arr);
}

int noOfBalancedBTsDP(int h)
{
    int* arr=new int[h+1];

    arr[0]=1;
    arr[1]=1;

    for(int i=2; i<h+1; i++)
    {
        int x=arr[i-1];
        int y=arr[i-2];

        int mod=(int) (pow(10, 9)) + 7;
        int ans=(int) ((((long long)(x) * x) % mod) + ((2* (long long)(x) * y) % mod)) % mod;
        arr[i]=ans;
    }

    return arr[h];
}

int main()
{
    int h;
    cout<<"Enter height of binary tree: ";
    cin>>h;

    cout<<"\nNo. of balanced BTs using Brute Force: ";
    cout<<noOfBalancedBTs(h);
    cout<<"\nNo. of balanced BTs using Memoization: ";
    cout<<noOfBalancedBTsMem(h);
    cout<<"\nNo. of balanced BTs using Dynamic Programming: ";
    cout<<noOfBalancedBTsDP(h)<<endl;
}
