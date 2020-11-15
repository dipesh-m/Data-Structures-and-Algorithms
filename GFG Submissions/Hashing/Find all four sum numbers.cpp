#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
const int mod = 1000000007;
const int MAX = 2e5;

void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>> ans;
    unordered_map<int, vector<vector<int>>> um;

    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int current=arr[i]+arr[j];
            int diff=k-current;

            if(um.count(diff)>0)
            {
                for(int l=0; l<um.at(diff).size(); l++)
                {
                    vector<int> im=um.at(diff).at(l);

                    im.push_back(arr[i]);
                    im.push_back(arr[j]);

                    ans.push_back(im);
                }
            }
        }

        for(int k=0; k<i; k++)
        {
            int current=arr[i]+arr[k];

            if(um.count(current)>0)
            {
                vector<int> im1;
                im1.push_back(arr[i]);
                im1.push_back(arr[k]);

                um.at(current).push_back(im1);
            }
            else
            {
                vector<vector<int>> im;
                vector<int> im1;
                im1.push_back(arr[i]);
                im1.push_back(arr[k]);

                im.push_back(im1);
                um.insert(make_pair(current, im));
            }
        }
    }

    if(ans.size()==0)
    {
        cout<<"-1"<<endl;
        return;
    }

    for(int i=0; i<ans.size(); i++)
    {
        sort(ans.at(i).begin(), ans.at(i).end());
    }
    sort(ans.begin(), ans.end());

    unordered_set<string> done;
    for(int i=0; i<ans.size(); i++)
    {
        string s;
        for(int j=0; j<ans.at(i).size(); j++)
        {
            s+=to_string(ans.at(i).at(j));
        }

        if(done.count(s)==0)
        {
            for(int j=0; j<ans.at(i).size(); j++)
            {
                cout<<ans.at(i).at(j)<<" ";
            }

            cout<<'$';
            done.insert(s);
        }
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
