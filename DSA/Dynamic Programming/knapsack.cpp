#include<iostream>
using namespace std;
#include<climits>

int knapsack(int N, int* weights, int* values, int W)
{
    if(W==0 || N==0)
    {
        return 0;
    }

    int x=INT_MIN;
    if(weights[0]<=W)
    {
        x=values[0] + knapsack(N-1, weights+1, values+1, W-weights[0]);
    }

    int y=knapsack(N-1, weights+1, values+1, W);

    return max(x, y);
}

int knapsackMemHelper(int N, int* weights, int* values, int W, int** arr_2D)
{
    if(W==0 || N==0)
    {
        return 0;
    }

    if(arr_2D[N][W]!=-1)
    {
        return arr_2D[N][W];
    }

    int x=INT_MIN;
    if(weights[0]<=W)
    {
        x=values[0] + knapsackMemHelper(N-1, weights+1, values+1, W-weights[0], arr_2D);
    }

    int y=knapsackMemHelper(N-1, weights+1, values+1, W, arr_2D);

    arr_2D[N][W]=max(x, y);
    return arr_2D[N][W];
}

int knapsackMem(int N, int* weights, int* values, int W)
{
    int** arr_2D=new int*[N+1];
    for(int i=0; i<N+1; i++)
    {
        arr_2D[i]=new int[W+1];
        for(int j=0; j<W+1; j++)
        {
            arr_2D[i][j]=-1;
        }
    }

    int ans=knapsackMemHelper(N, weights, values, W, arr_2D);

    for(int i=0; i<N+1; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int knapsackDP(int N, int* weights, int* values, int W)
{
    int** arr_2D=new int*[N+1];
    for(int i=0; i<N+1; i++)
    {
        arr_2D[i]=new int[W+1];
    }

    for(int i=0; i<=W; i++)
    {
        arr_2D[0][i]=0;
    }
    for(int i=0; i<=N; i++)
    {
        arr_2D[i][0]=0;
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=W; j++)
        {
            int x=INT_MIN;
            if(weights[N-i]<=j)
            {
                x=values[N-i] + arr_2D[i-1][j-weights[N-i]];
            }

            int y=arr_2D[i-1][j];

            arr_2D[i][j]=max(x, y);
        }
    }

    int ans=arr_2D[N][W];

    for(int i=0; i<N+1; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int main()
{
    int N;
    cout<<"Enter number of items: ";
    cin>>N;
    int* weights=new int[N];
    int* values=new int[N];

    cout<<endl<<"Enter weights of items:- "<<endl;
    for(int i=0; i<N; i++)
    {
        cin>>weights[i];
    }
    cout<<endl<<"Enter values of items:- "<<endl;
    for(int i=0; i<N; i++)
    {
        cin>>values[i];
    }

    int W;
    cout<<endl<<"Enter maximum weight that can be carried in knapsack: ";
    cin>>W;

    cout<<endl;
    cout<<"Maximum Value using Brute-Force: "<<knapsack(N, weights, values, W)<<endl;
    cout<<"Maximum Value using Memoization: "<<knapsackMem(N, weights, values, W)<<endl;
    cout<<"Maximum Value using Dynamic Programming: "<<knapsackDP(N, weights, values, W)<<endl;

    delete []weights;
    delete []values;
}
