#include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string s)
{
    //Your code here
    int i=s.length()-1, ans=0, j=1;
    bool neg=false;

    if(s[0]=='-')
    {
        neg=true;
    }
    while(i>=0)
    {
        if(neg==true && i==0)
        {
            i--;
            continue;
        }

        if(s[i]<'0' || s[i]>'9')
        {
            return -1;
        }
        ans=ans+(j*(s[i]-'0'));
        j*=10;
        i--;
    }

    if(neg)
    {
        return (-1)*ans;
    }

    return ans;
}
