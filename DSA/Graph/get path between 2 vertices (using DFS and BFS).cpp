#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<unordered_map>

void getPathDFSHelper(int** edges, int n, int sv, bool* visited, int v2, vector<int>* ans)
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
                ans->push_back(i);
                ans->push_back(sv);
                return;
            }

            getPathDFSHelper(edges, n, i, visited, v2, ans);
            if(ans->size()==0)
            {
                continue;
            }
            else
            {
                ans->push_back(sv);
                return;
            }
        }
    }
}

void getPathDFS(int** edges, int n, int v1, int v2)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    vector<int>* ans=new vector<int>;
    getPathDFSHelper(edges, n, v1, visited, v2, ans);

    if(ans->size()==0)
    {
        cout<<"PATH DOESN'T EXIST"<<endl;
    }
    else
    {
        for(int i=ans->size()-1; i>=0; i--)
        {
            cout<<ans->at(i)<<" ";
        }
    }

    delete []visited;
    delete ans;
}

void getPathBFSHelper(int** edges, int n, int sv, bool* visited, int v2, vector<int>* ans)
{
    unordered_map<int, int> um;

    queue<int> pending;
    pending.push(sv);

    visited[sv]=true;
    int m=-1;
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
                    m=i;
                    um[i]=_front;
                    break;
                }

                pending.push(i);
                visited[i]=true;

                um[i]=_front;
            }
        }
    }

    if(m==v2)
    {
        ans->push_back(m);
        while(m!=sv)
        {
            int intermediate=um.at(m);
            ans->push_back(intermediate);
            m=intermediate;
        }
    }
}

void getPathBFS(int** edges, int n, int v1, int v2)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    vector<int>* ans=new vector<int>;
    getPathBFSHelper(edges, n, v1, visited, v2, ans);

    if(ans->size()==0)
    {
        cout<<"PATH DOESN'T EXIST"<<endl;
    }
    else
    {
        for(int i=ans->size()-1; i>=0; i--)
        {
            cout<<ans->at(i)<<" ";
        }
    }

    delete []visited;
    delete ans;
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

    cout<<"PATH USING DFS:-"<<endl;
    getPathDFS(edges, n, v1, v2);

    cout<<"\nPATH USING BFS:-"<<endl;
    getPathBFS(edges, n, v1, v2);

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
