#include<iostream>
using namespace std;

int linearSearch(int* arr, int n, int x)
{
    for(int i=0; i<n ;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<endl;

    int* arr=new int[n];
    cout<<"Enter elements of array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<endl;

    int x;
    cout<<"Enter the element to be searched?: ";
    cin>>x;
    cout<<endl;

    int ans=linearSearch(arr, n, x);
    if(ans==-1)
    {
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
    else
    {
        cout<<"ELEMENT FOUND AT POSITION: "<<ans;
    }

    delete []arr;

    return 0;
}
