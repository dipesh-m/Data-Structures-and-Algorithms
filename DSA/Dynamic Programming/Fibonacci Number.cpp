#include<iostream>
using namespace std;

int fib_1(int n)
{
    if(n<=1)
    {
        return n;
    }

    int a=fib_1(n-1);
    int b=fib_1(n-2);

    return a+b;
}

int fib_2_helper(int n, int* arr)
{
    if(n<=1)
    {
        return n;
    }

    if(arr[n]!=-1)
    {
        return arr[n];
    }

    int a=fib_2_helper(n-1, arr);
    int b=fib_2_helper(n-2, arr);

    arr[n]=a+b;

    return arr[n];
}

int fib_2(int n)
{
    int* arr=new int[n+1];
    for(int i=0; i<n+1; i++)
    {
        arr[i]=-1;
    }

    return fib_2_helper(n, arr);
}

int fib_3(int n)
{
    int* arr=new int[n+1];

    arr[0]=0;
    arr[1]=1;

    for(int i=2; i<n+1; i++)
    {
        arr[i]=arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main()
{
    int n;
    cout<<"Enter the Fibonacci number to find: ";
    cin>>n;

    cout<<"\n"<<n<<"th Fibonacci number using Brute Force: ";
    cout<<fib_1(n);
    cout<<"\n"<<n<<"th Fibonacci number using Memoization: ";
    cout<<fib_2(n);
    cout<<"\n"<<n<<"th Fibonacci number using Dynamic Programming: ";
    cout<<fib_3(n)<<endl;
}
