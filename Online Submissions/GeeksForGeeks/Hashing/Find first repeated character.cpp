


//Sol 1



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    int arr[26]={0}, f=0;
    char ans;
    for(int i=0; i<s.length(); i++)
    {
        arr[s[i]-'a']++;
        if(arr[s[i]-'a']==2)
        {
            f=1;
            ans=s[i];
            break;
        }
    }

    if(f==0)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
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



/*
//Sol 2



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    string s;
    cin>>s;

    unordered_map<char, pair<int, pair<int, int>>> um;
    for(int i=0; i<s.length(); i++)
    {
        if(um.count(s[i])>0)
        {
            if(um.at(s[i]).second.second==1)
            {
                um.at(s[i]).first=i;
                um.at(s[i]).second.second++;
            }
            um.at(s[i]).second.first++;
        }
        else
        {
            um[s[i]]=make_pair(i, make_pair(1, 1));
        }
    }

    int ans=INT_MAX;
    for(auto it=um.begin(); it!=um.end(); it++)
    {
        if(it->second.second.first>1 && it->second.second.second==2 && it->second.first<ans)
        {
            ans=it->second.first;
        }
    }

    if(ans==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<s[ans]<<endl;
    }
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
