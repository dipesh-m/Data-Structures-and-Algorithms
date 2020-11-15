#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high);
/* The main function that implements QuickSort
 arr[] --> Array to be sorted, low  --> Starting index, high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/
/* This function takes last element as pivot, places  the pivot element
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int* arr, int si, int ei)
{
   // Your code here
   int pivot=arr[ei];
   int c=0;
   for(int k=si; k<ei; k++)
   {
       if(arr[k]<=pivot)
       {
           c++;
       }
   }

   int pivotIndex=si+c;
   swap(arr[ei], arr[pivotIndex]);

   int i=si, j=ei;
   while(i<pivotIndex && j>pivotIndex)
   {
       if(arr[i]<=pivot)
       {
           i++;
       }
       else if(arr[j]>pivot)
       {
           j--;
       }
       else
       {
           swap(arr[i], arr[j]);
           i++;
           j--;
       }
   }

   return pivotIndex;
}
