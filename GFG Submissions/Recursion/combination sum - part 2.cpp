#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define cases int t; cin>>t; for(int i=1; i<=t; i++)
typedef pair<int, int> pi;
const int mod = 1000000007;
const int MAX = 2e5;

void start(int* arr, int n, int k, vector<vector<int>*>* ans, vector<int>* im)
{
    int sum=0;
    for(int i=0; i<im->size(); i++)
    {
        sum+=im->at(i);
    }
    if(sum==k)
    {
        ans->push_back(im);
    }

    if(n==0)
    {
        return;
    }

    vector<int>* im1=new vector<int>(*im);
    im1->push_back(arr[0]);

    start(arr+1, n-1, k, ans, im1);
    start(arr+1, n-1, k, ans, im);
}

void solve()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;

    sort(arr, arr+n);

    vector<vector<int>*>* ans=new vector<vector<int>*>;
    vector<int>* im=new vector<int>;
    start(arr, n, k, ans, im);

    bool something=false;
    unordered_set<string> us;

    for(int i=0; i<ans->size(); i++)
    {
        int sum=0;
        for(int j=0; j<ans->at(i)->size(); j++)
        {
            sum+=ans->at(i)->at(j);
        }
        if(sum==k)
        {
            something=true;

            string s;
            for(int j=0; j<ans->at(i)->size(); j++)
            {
                s+=to_string(ans->at(i)->at(j));
            }

            if(us.count(s)>0)
            {
                continue;

            }
            else
            {
                us.insert(s);

                cout<<"(";
                for(int j=0; j<ans->at(i)->size(); j++)
                {
                    if(j!=(ans->at(i)->size()-1))
                        cout<<ans->at(i)->at(j)<<" ";
                    else
                        cout<<ans->at(i)->at(j);
                }
                cout<<")";
            }
        }
    }

    if(something==false)
    {
        cout<<"Empty";
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
