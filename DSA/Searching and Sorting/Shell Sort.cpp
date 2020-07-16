#include<iostream>
using namespace std;
#include<cmath>

void shellSort(int* arr, int n)
{
    for(int gap=floor(n/2); gap>=1; gap/=2)
    {
        for(int j=gap; j<n; j++)
        {
            for(int i=j-gap; i>=0; i=i-gap)
            {
                if(arr[i+gap]<arr[i])
                {
                    int temp=arr[i+gap];
                    arr[i+gap]=arr[i];
                    arr[i]=temp;
                }
                else
                {
                    break;
                }
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

    shellSort(arr, n);

    cout<<"Sorted Array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;

    return 0;
}
