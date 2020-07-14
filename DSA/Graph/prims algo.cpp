#include<iostream>
using namespace std;
#include<climits>

int giveMinWeightVertex(int* weight, bool* visited, int n)
{
   int ans=-1;
   int ansWeight=INT_MAX;

   for(int i=0; i<n; i++)
   {
       if(weight[i]<ansWeight && visited[i]==false)
       {
           ansWeight=weight[i];
           ans=i;
       }
   }

   return ans;
}

void prims(int** edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    int* weight=new int[n];
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            weight[i]=0;
        }
        else
        {
            weight[i]=INT_MAX;
        }
    }

    int* parent=new int[n];
    parent[0]=-1;

    for(int _count=0; _count<n; _count++)
    {
        int vertex=giveMinWeightVertex(weight, visited, n);

        visited[vertex]=true;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false && edges[vertex][i]!=-1)
            {
                if(edges[vertex][i] < weight[i])
                {
                    weight[i]=edges[vertex][i];
                    parent[i]=vertex;
                }
            }
        }
    }

    int weightMST=0;
    cout<<"MST:-"<<endl;
    for(int i=1; i<n; i++)
    {
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;

        weightMST+=weight[i];
    }

    cout<<"\nTOTAL WEIGHT OF MST = "<<weightMST<<endl;

    delete []visited;
    delete []weight;
    delete []parent;
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
            edges[i][j]=-1;
        }
    }

    int e;
    cout<<"ENTER NUMBER OF EDGES: ";
    cin>>e;
    cout<<endl;

    cout<<"ENTER "<<e<<" EDGES IN FORMAT: SOURCE DESTINATION WEIGHT"<<endl;
    for(int i=0; i<e; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;

        edges[s][d]=w;
        edges[d][s]=w;
    }

    cout<<endl;

    prims(edges, n);

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
