#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<unordered_map>

void isConnectedHelper(int** edges, int n, int sv, bool* visited)
{
    visited[sv]=true;
    for(int i=0; i<n; i++)
    {
        if(i==sv)
        {
            continue;
        }

        if(edges[sv][i]==1)
        {
            if(visited[i]==true)
            {
                continue;
            }

            isConnectedHelper(edges, n, i, visited);
        }
    }
}

bool isConnected(int** edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    isConnectedHelper(edges, n, 0, visited);

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cout<<"ENTER NUMBER OF VERTICES: ";
    cin>>n;
    cout<<endl;

    int** edges=new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j]=0;
        }
    }

    int e;
    cout<<"ENTER NUMBER OF EDGES: ";
    cin>>e;
    cout<<endl;

    cout<<"ENTER "<<e<<" EDGES IN FORMAT: SOURCE DESTINATION"<<endl;
    for(int i=0; i<e; i++)
    {
        int f, s;
        cin>>f>>s;

        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<endl;

    if(isConnected(edges, n))
    {
        cout<<"GRAPH IS CONNECTED"<<endl;
    }
    else
    {
        cout<<"GRAPH IS NOT CONNECTED"<<endl;
    }

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
