#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

bool start(int** g, int n, int x, int y, int** vis)
{
    vis[x][y]=1;

    if(g[x][y]==2)
    {
        return true;
    }

    if(x!=0 && vis[x-1][y]==0 && (g[x-1][y]==3 || g[x-1][y]==2))
    {
        if(start(g, n, x-1, y, vis))
        {
            return true;
        }
    }
    if(x!=n-1 && vis[x+1][y]==0 && (g[x+1][y]==3 || g[x+1][y]==2))
    {
        if(start(g, n, x+1, y, vis))
        {
            return true;
        }
    }
    if(y!=0 && vis[x][y-1]==0 && (g[x][y-1]==3 || g[x][y-1]==2))
    {
        if(start(g, n, x, y-1, vis))
        {
            return true;
        }
    }
    if(y!=n-1 && vis[x][y+1]==0 && (g[x][y+1]==3 || g[x][y+1]==2))
    {
        if(start(g, n, x, y+1, vis))
        {
            return true;
        }
    }

    return false;
}

void solve()
{
    int n;
    cin>>n;

    int** g=new int*[n];
    int** vis=new int*[n];
    for(int i=0; i<n; i++)
    {
        g[i]=new int[n];
        vis[i]=new int[n];
    }

    int x=0, y=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            vis[i][j]=0;
            cin>>g[i][j];

            if(g[i][j]==1)
            {
                x=i;
                y=j;
            }
        }
    }

    cout<<start(g, n, x, y, vis)<<endl;

    for(int i=0; i<n; i++)
    {
        delete []g[i];
        delete []vis[i];
    }
    delete []g;
    delete []vis;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cases
    {
        solve();
    }

    return 0;
}
