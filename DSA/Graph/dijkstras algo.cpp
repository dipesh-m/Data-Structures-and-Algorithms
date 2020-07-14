#include<iostream>
using namespace std;
#include<climits>

int giveMinDistanceVertex(int *distance, bool *visited, int n)
{
    int ans=-1;
    int ansDistance=INT_MAX;

    for(int i=0; i<n; i++)
    {
        if (distance[i]<ansDistance && visited[i]==false)
        {
            ansDistance=distance[i];
            ans=i;
        }
    }

    return ans;
}

void dijkstras(int **edges, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    int* distance=new int[n];
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            distance[i]=0;
        }
        else
        {
            distance[i]=INT_MAX;
        }
    }

    for(int _count=0; _count<n; _count++)
    {
        int vertex=giveMinDistanceVertex(distance, visited, n);

        visited[vertex]=true;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false && edges[vertex][i]!=-1)
            {
                if(edges[vertex][i]+distance[vertex]<distance[i])
                {
                    distance[i]=edges[vertex][i]+distance[vertex];
                }
            }
        }
    }

    cout<<"SHORTEST DISTANCE POSSIBLE FROM VERTEX 0 TO EVERY OTHER VERTEX:-"<<endl;
    for(int i=1; i<n; i++)
    {
        cout<<"0 -> "<<i<<" : "<<distance[i]<<endl;
    }

    delete []visited;
    delete []distance;
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

    dijkstras(edges, n);

    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }

    delete []edges;
}
