#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool dfs(vector<int> g[], int si, bool visited[], int p)
{
    visited[si]=true;

    for(int i=0; i<(g[si].size()); i++)
    {
        if(visited[g[si][i]]==false)
        {
            bool a=dfs(g, g[si][i], visited, si);
            if(a==true)
            {
                return true;
            }
        }
        else if((g[si][i])!=p)
        {
            return true;
        }
    }

    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool visited[V];
   memset(visited, false, sizeof(visited));

   for(int i=0; i<V; i++)
   {
       if(!visited[i])
       {
           bool a=dfs(g, i, visited, -1);
           if(a==true)
           {
               return 1;
           }
       }
   }

   return 0;
}


// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
