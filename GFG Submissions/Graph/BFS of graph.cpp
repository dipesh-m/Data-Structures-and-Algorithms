#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    bool visited[N];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(0);

    vector<int> ans;

    while(q.size()!=0)
    {
        int _front=q.front();
        q.pop();

        ans.push_back(_front);
        visited[_front]=true;

        for(vector<int>::size_type i=0; i<(g[_front].size()); i++)
        {
            if(visited[g[_front][i]]==false)
            {
                q.push(g[_front][i]);
                visited[g[_front][i]]=true;
            }
        }
    }

    return ans;
}
