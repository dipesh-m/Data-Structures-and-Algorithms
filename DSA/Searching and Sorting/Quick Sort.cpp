#include<iostream>
using namespace std;

int partition_array(int* arr, int si, int ei)
{
    int count_small=0;
    for(int i=(si+1);i<=ei;i++)
    {
        if(arr[i]<=arr[si])
        {
            count_small++;
        }
    }

    int c=si+count_small;
    int temp=arr[c];
    arr[c]=arr[si];
    arr[si]=temp;

    int i=si, j=ei;
    while(i<c && j>c)
    {
        if(arr[i]<= arr[c])
        {
            i++;
        }
        else if(arr[j]>arr[c])
        {
            j--;
        }
        else
        {
            int temp_1=arr[j];
            arr[j]=arr[i];
            arr[i]=temp_1;

            i++;
            j--;
        }
    }

    return c;
}

void quickSort(int* arr, int si, int ei)
{
    if(si>=ei)
    {
        return;
    }

    int c=partition_array(arr, si, ei);

    quickSort(arr, si, c-1);
    quickSort(arr, c+1, ei);
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

    quickSort(arr, 0, n-1);

    cout<<"Sorted Array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;

    return 0;
}
