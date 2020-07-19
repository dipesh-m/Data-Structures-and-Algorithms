#include<iostream>
using namespace std;
#include<climits>

int minCostPathHelper(int** input, int m, int n, int i, int j)
{
    if(i==m-1 && j==n-1)
    {
        return input[i][j];
    }

    int x=INT_MAX, y=INT_MAX, z=INT_MAX;
    if(i<m-1)
    {
        x=minCostPathHelper(input, m, n, i+1, j);
    }
    if(j<n-1)
    {
        y=minCostPathHelper(input, m, n, i, j+1);
    }
    if(i<m-1 && j<n-1)
    {
        z=minCostPathHelper(input, m, n, i+1, j+1);
    }

    int ans=min(x, min(y,z)) + input[i][j];

    return ans;
}

int minCostPath(int** input, int m, int n)
{
    return minCostPathHelper(input, m, n, 0, 0);
}

int minCostPathMemHelper(int** input, int m, int n, int i, int j, int** arr_2D)
{
    if(i==m-1 && j==n-1)
    {
        return input[i][j];
    }

    if(arr_2D[i][j]!=-1)
    {
        return arr_2D[i][j];
    }

    int x=INT_MAX, y=INT_MAX, z=INT_MAX;
    if(i<m-1)
    {
        x=minCostPathMemHelper(input, m, n, i+1, j, arr_2D);
    }
    if(j<n-1)
    {
        y=minCostPathMemHelper(input, m, n, i, j+1, arr_2D);
    }
    if(i<m-1 && j<n-1)
    {
        z=minCostPathMemHelper(input, m, n, i+1, j+1, arr_2D);
    }

    int ans=min(x, min(y,z)) + input[i][j];
    arr_2D[i][j]=ans;

    return arr_2D[i][j];
}

int minCostPathMem(int** input, int m, int n)
{
    int** arr_2D=new int*[m];
    for(int i=0; i<m; i++)
    {
        arr_2D[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            arr_2D[i][j]=-1;
        }
    }

    int ans=minCostPathMemHelper(input, m, n, 0, 0, arr_2D);

    for(int i=0; i<m; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int minCostPathDP(int** input, int m, int n)
{
    int** arr_2D=new int*[m];
    for(int i=0; i<m; i++)
    {
        arr_2D[i]=new int[n];
    }

    arr_2D[m-1][n-1]=input[m-1][n-1];

    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i==m-1 && j==n-1)
            {
                continue;
            }

            int x=INT_MAX, y=INT_MAX, z=INT_MAX;
            if(i<m-1)
            {
                x=arr_2D[i+1][j];
            }
            if(j<n-1)
            {
                y=arr_2D[i][j+1];
            }
            if(i<m-1 && j<n-1)
            {
                z=arr_2D[i+1][j+1];
            }

            int ans=min(x, min(y,z)) + input[i][j];
            arr_2D[i][j]=ans;
        }
    }

    int ans=arr_2D[0][0];

    for(int i=0; i<m; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int main()
{
    int m;
    cout<<"Enter number of rows in matrix: ";
    cin>>m;

    cout<<endl;
    int n;
    cout<<"Enter number of columns in matrix: ";
    cin>>n;

    cout<<endl<<"Enter elements of matrix:- "<<endl;
    int** input=new int*[m];
    for(int i=0; i<m; i++)
    {
        input[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>input[i][j];
        }
    }

    cout<<endl;
    cout<<"Min. Cost Path using Brute-Force: "<<minCostPath(input, m, n)<<endl;
    cout<<"Min. Cost Path using Memoization: "<<minCostPathMem(input, m, n)<<endl;
    cout<<"Min. Cost Path using Dynamic Programming: "<<minCostPathDP(input, m, n)<<endl;

    for(int i=0; i<m; i++)
    {
        delete []input[i];
    }

    delete []input;
}

