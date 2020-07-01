#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void start(char s[], int l, int r)
{
    if(l==r)
    {
        cout<<s<<" ";
    }

    for(int i=l; i<=r; i++)
    {
        swap(s[l], s[i]);
        sort(s+l+1, s+r+1);
        start(s, l+1, r);
        sort(s+l+1, s+r+1);
        swap(s[l], s[i]);
    }
}

void solve()
{
    char s[10];
    cin>>s;

    sort(s, s+strlen(s));
    start(s, 0, strlen(s)-1);
    cout<<endl;
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



//Without using inbuilt next_permutation() function



/*
#include <bits/stdc++.h>
using namespace std;
#include<algorithm>

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    sort(s.begin(), s.end());

    bool cont=true;
    while(cont)
    {
        cout<<s<<" ";
        cont=next_permutation(s.begin(), s.end());
    }

    cout<<endl;
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
*/
