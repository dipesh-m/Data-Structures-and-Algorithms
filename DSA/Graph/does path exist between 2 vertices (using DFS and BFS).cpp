#include<iostream>
using namespace std;
#include<queue>

bool hasPathHelperDFS(int** edges, int n, int sv, bool* visited, int v2)
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

            if(i==v2)
            {
                return true;
            }

            bool ans=hasPathHelperDFS(edges, n, i, visited, v2);
            if(ans==false)
            {
                continue;
            }
            else
            {
                return ans;
            }
        }
    }

    return false;
}

bool hasPathDFS(int** edges, int n, int v1, int v2)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    bool ans=hasPathHelperDFS(edges, n, v1, visited, v2);

    delete []visited;
    return ans;
}

bool hasPathHelperBFS(int** edges, int n, int sv, bool* visited, int v2)
{
    queue<int> pending;
    pending.push(sv);

    visited[sv]=true;
    while(pending.size()!=0)
    {
        int _front=pending.front();
        pending.pop();

        for(int i=0; i<n; i++)
        {
            if(i==sv)
            {
                continue;
            }

            if(edges[_front][i]==true)
            {
                if(visited[i]==true)
                {
                    continue;
                }

                if(i==v2)
                {
                    return true;
                }

                pending.push(i);
                visited[i]=true;

            }
        }
    }

    return false;
}

bool hasPathBFS(int** edges, int n, int v1, int v2)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    bool ans=hasPathHelperBFS(edges, n, v1, visited, v2);

    delete []visited;
    return ans;
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

    int v1;
    cout<<"ENTER FIRST VERTEX: ";
    cin>>v1;
    int v2;
    cout<<"\nENTER SECOND VERTEX: ";
    cin>>v2;
    cout<<endl;

    if(hasPathDFS(edges, n, v1, v2))
    {
        cout<<"PATH FOUND THROUGH DFS"<<endl;
    }
    else
    {
        cout<<"PATH NOT FOUND THROUGH DFS"<<endl;
    }

    if(hasPathBFS(edges, n, v1, v2))
    {
        cout<<"PATH FOUND THROUGH BFS"<<endl;
    }
    else
    {
        cout<<"PATH NOT FOUND THROUGH BFS"<<endl;
    }

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
