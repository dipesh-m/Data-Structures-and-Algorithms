#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<unordered_map>

void allConnectedComponentsHelper(int** edges, int n, int sv, bool* visited, vector<int>* im)
{
    im->push_back(sv);

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

            allConnectedComponentsHelper(edges, n, i, visited, im);
        }
    }
}

vector<vector<int>*>* allConnectedComponents(int** edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    vector<vector<int>*>* ans=new vector<vector<int>*>;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            vector<int>* im=new vector<int>;
            allConnectedComponentsHelper(edges, n, i, visited, im);
            ans->push_back(im);
        }
    }

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

    vector<vector<int>*>* ans=allConnectedComponents(edges, n);
    cout<<"ALL CONNECTED COMPONENTS:-"<<endl;
    for(int i=0; i<ans->size(); i++)
    {
        for(int j=0; j<ans->at(i)->size(); j++)
        {
            cout<<ans->at(i)->at(j)<<" ";
        }

        cout<<endl;
    }

    for(int i=0; i<ans->size(); i++)
    {
        delete ans->at(i);
    }

    delete ans;

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
