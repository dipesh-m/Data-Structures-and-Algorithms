#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n;
    cin>>n;
    double arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;

    double median=arr[0];
    s.push(arr[0]);
    cout<<(int)median<<endl;

    for(int i=1; i<n; i++)
    {
        double x=arr[i];

        if(s.size()==g.size())
        {
            if(x<median)
            {
                s.push(x);
                median=(double)s.top();
            }
            else
            {
                g.push(x);
                median=(double)g.top();
            }
        }
        else if(s.size()>g.size())
        {
            if(x<median)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }

            median=(s.top()+g.top())/2.0;
        }
        else
        {
            if(x<median)
            {
                s.push(x);
            }
            else
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }

            median=(s.top()+g.top())/2.0;
        }

        cout<<(int)median<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
