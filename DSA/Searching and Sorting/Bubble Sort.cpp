#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
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

    bubbleSort(arr, n);

    cout<<"Sorted Array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;

    return 0;
}
