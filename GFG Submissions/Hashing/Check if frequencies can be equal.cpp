#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

bool allSame(int arr[])
{
    int ind;
    for(int i=0; i<26; i++)
    {
        if(arr[i]!=0)
        {
            ind=i;
            break;
        }
    }

    int x=arr[ind];
    for(int i=ind+1; i<26; i++)
    {
        if(arr[i]!=0 && arr[i]!=x)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    string s;
    cin>>s;

    int arr[26]={0};
    for(int i=0; i<s.length(); i++)
    {
        arr[s[i]-'a']++;
    }

    if(allSame(arr))
    {
        cout<<"1"<<endl;
        return;
    }

    for(char i='a'; i<='z'; i++)
    {
        if(arr[i-'a']!=0)
        {
            arr[i-'a']--;
            if(allSame(arr))
            {
                cout<<"1"<<endl;
                return;
            }
            arr[i-'a']++;
        }
    }

    cout<<"0"<<endl;
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
