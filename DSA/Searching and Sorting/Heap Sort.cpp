#include<iostream>
using namespace std;

void heapSort(int* arr, int n)
{
    for(int i=1; i<n; i++)
    {
       int childIndex=i;
       int parentIndex=(childIndex-1)/2;

       while(childIndex>0)
       {
           if(arr[childIndex]>arr[parentIndex])
           {
               int temp=arr[parentIndex];
               arr[parentIndex]=arr[childIndex];
               arr[childIndex]=temp;
           }
           else
           {
               break;
           }

           childIndex=parentIndex;
           parentIndex=(childIndex-1)/2;
       }
    }

    for(int heapLast=n-1; heapLast>=0 ; heapLast--)
    {
        int temp=arr[0];
        arr[0]=arr[heapLast];
        arr[heapLast]=temp;

        int parentIndex=0;
        int leftChildIndex=2*parentIndex + 1;
        int rightChildIndex=2*parentIndex + 2;

        while(leftChildIndex<heapLast)
        {
            int maxIndex=parentIndex;

            if(arr[leftChildIndex]>arr[maxIndex])
            {
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<heapLast && arr[rightChildIndex]>arr[maxIndex])
            {
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex)
            {
                break;
            }

            int temp=arr[parentIndex];
            arr[parentIndex]=arr[maxIndex];
            arr[maxIndex]=temp;

            parentIndex=maxIndex;
            leftChildIndex=2*parentIndex + 1;
            rightChildIndex=2*parentIndex + 2;
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

    heapSort(arr, n);

    cout<<"Sorted Array:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete []arr;

    return 0;
}
