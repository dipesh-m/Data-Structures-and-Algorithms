#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;

        cin>>a;
        cin>>b;

        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     int i=0;
     while(i<s.length())
     {
         if(s[i]==x[0])
         {
             if(s.substr(i, x.length())==x)
             {
                 return i;
             }
         }
         i++;
     }

     return -1;
}
