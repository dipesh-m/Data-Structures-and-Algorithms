#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool dfs(vector<int> g[], int si, bool visited[], bool recStack[])
{
    visited[si]=true;
    recStack[si]=true;

    for(int i=0; i<(g[si].size()); i++)
    {
        if(visited[g[si][i]]==false)
        {
            bool a=dfs(g, g[si][i], visited, recStack);
            if(a==true)
            {
                return true;
            }
        }
        else if(recStack[g[si][i]]==true)
        {
            return true;
        }
    }

    recStack[si]=false;

    return false;
}

bool isCyclic(int V, vector<int> g[])
{
   // Your code here
   bool visited[V], recStack[V];
   memset(visited, false, sizeof(visited));
   memset(recStack, false, sizeof(recStack));

   for(int i=0; i<V; i++)
   {
       if(!visited[i])
       {
           bool a=dfs(g, i, visited, recStack);
           if(a==true)
           {
               return 1;
           }
       }
   }

   return 0;
}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends
