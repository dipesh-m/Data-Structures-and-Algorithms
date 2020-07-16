#include<iostream>
using namespace std;

int binarySearch(int* arr, int n, int x)
{
    int s=0, e=n-1, mid;
    while (s<=e)
    {
        mid=(s+e)/2;

        if(arr[mid]==x)
        {
            return mid;
        }
        else if(x<arr[mid])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
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

    int ans=binarySearch(arr, n, x);
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
