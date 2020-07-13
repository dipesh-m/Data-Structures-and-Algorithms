#include<iostream>
using namespace std;
#include<queue>

void printDFS(int** edges, int n, int sv, bool* visited)
{
    cout<<sv<<endl;
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

            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int** edges, int n, int sv, bool* visited)
{
    queue<int> pending;
    pending.push(sv);

    while(pending.size()!=0)
    {
        int _front=pending.front();
        pending.pop();

        cout<<_front<<endl;
        visited[_front]=true;

        for(int i=0; i<n; i++)
        {
            if(i==_front)
            {
                continue;
            }

            if(edges[_front][i]==1)
            {
                if(visited[i]==true)
                {
                    continue;
                }

                pending.push(i);
                visited[i]=true;
            }
        }
    }
}

void DFS(int** edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            printDFS(edges, n, i, visited);
        }
    }

    delete []visited;
}

void BFS(int** edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            printBFS(edges, n, i, visited);
        }
    }

    delete []visited;
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

    cout<<"DFS"<<endl;
    DFS(edges, n);

    cout<<"BFS"<<endl;
    BFS(edges, n);

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
