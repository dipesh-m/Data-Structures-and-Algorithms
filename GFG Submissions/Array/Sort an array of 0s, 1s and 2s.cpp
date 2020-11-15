#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    int c0=0,c1=0,c2=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]==0)
            c0++;
        else if(a[i]==1)
            c1++;
        else
            c2++;
    }

    int j=0;
    while(c0!=0)
    {
        c0--;
        a[j]=0;
        j++;
    }

    while(c1!=0)
    {
        c1--;
        a[j]=1;
        j++;
    }

    while(c2!=0)
    {
        c2--;
        a[j]=2;
        j++;
    }
}
