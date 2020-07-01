#include<bits/stdc++.h>
using namespace std;

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsHelper(vector<int> g[], int N, int si, bool* visited, vector<int>* ans)
{
    ans->push_back(si);
    visited[si]=true;

    for(vector<int>::size_type i=0; i<g[si].size(); i++)
    {
        if(visited[g[si][i]]==false)
        {
           dfsHelper(g, N, g[si][i], visited, ans);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    // Your code here
    bool visited[N];
    memset(visited, false, sizeof(visited));
    vector<int>* ans=new vector<int>;
    dfsHelper(g, N, 0, visited, ans);

    return *ans;
}


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);           //READ ONLY DRIVER CODE DIDN'T PASS vis ARRAY??????
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
