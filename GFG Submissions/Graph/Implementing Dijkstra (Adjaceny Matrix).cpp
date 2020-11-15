#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{

   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);

}

int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        vector<int> res=dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int getMinVertex(int V, int* weights, bool* visited)
{
    int ans=-1;
    int minWeight=INT_MAX;
    for(int i=0; i<V; i++)
    {
        if(weights[i]<minWeight && visited[i]==false)
        {
            minWeight=weights[i];
            ans=i;
        }
    }

    return ans;
}

vector<int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    bool visited[V]={false};

    int weights[V];
    for(int i=0; i<V; i++)
    {
        weights[i]=INT_MAX;
    }
    weights[src]=0;

    for(int _count=0; _count<V; _count++)
    {
        int minVertex=getMinVertex(V, weights, visited);
        visited[minVertex]=true;

        for(int j=0; j<V; j++)
        {
            if(visited[j]==false && (g[minVertex][j])!=0)
            {
                if((g[minVertex][j]+weights[minVertex])<weights[j])
                {
                    weights[j]=g[minVertex][j]+weights[minVertex];
                }
            }
        }
    }

    vector<int> v;
    for(int i=0; i<V; i++)
    {
        v.push_back(weights[i]);
    }

    return v;
}
