#include<iostream>
using namespace std;

void merge2SortedArrays(int* arr, int si, int ei)
{
    int size_output=(ei-si)+1;
    int* output=new int[size_output];

    int mid=(si+ei)/2;
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei)
    {
        if(arr[i]<=arr[j])
        {
            output[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            output[k]=arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        output[k]=arr[i];
        i++;
        k++;
    }

    while(j<=ei)
    {
        output[k]=arr[j];
        j++;
        k++;
    }

    int x=0;
    for(int l=si; l<=ei; l++)
    {
        arr[l]=output[x];
        x++;
    }

    delete []output;
}

void mergeSort(int* arr, int si, int ei)
{
    if(si>=ei)
    {
        return;
    }

    int mid=(si+ei)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge2SortedArrays(arr, si, ei);
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

    mergeSort(arr, 0, n-1);

    cout<<"Sorted Array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;

    return 0;
}
