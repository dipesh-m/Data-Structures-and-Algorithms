#include<iostream>
using namespace std;
#include<string>

int LCS(string a, string b)
{
    if(a.size()==0 || b.size()==0)
    {
        return 0;
    }

    if(a[0]==b[0])
    {
        int x=LCS(a.substr(1), b.substr(1));
        return 1+x;
    }
    else
    {
        int x=max(LCS(a, b.substr(1)), max(LCS(a.substr(1), b), LCS(a.substr(1), b.substr(1))));
        return x;
    }
}

int LCSMemHelper(string a, string b, int** arr_2D)
{
    if(a.size()==0 || b.size()==0)
    {
        return 0;
    }

    int m=a.size();
    int n=b.size();

    if(arr_2D[m][n]!=-1)
    {
        return arr_2D[m][n];
    }

    if(a[0]==b[0])
    {
        int x=LCSMemHelper(a.substr(1), b.substr(1), arr_2D);
        arr_2D[m][n]=1+x;

        return arr_2D[m][n];
    }
    else
    {
        int x=max(LCSMemHelper(a, b.substr(1), arr_2D), LCSMemHelper(a.substr(1), b, arr_2D));
        arr_2D[m][n]=x;

        return arr_2D[m][n];
    }
}

int LCSMem(string a, string b)
{
    int** arr_2D=new int*[a.size()+1];
    for(int i=0; i<a.size()+1; i++)
    {
        arr_2D[i]=new int[b.size()+1];
        for(int j=0; j<b.size()+1; j++)
        {
            arr_2D[i][j]=-1;
        }
    }

    int ans=LCSMemHelper(a, b, arr_2D);

    for(int i=0; i<a.size()+1; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int LCSDP(string a, string b)
{
    int** arr_2D=new int*[a.size()+1];
    for(int i=0; i<a.size()+1; i++)
    {
        arr_2D[i]=new int[b.size()+1];
    }

    for(int i=0; i<=b.size(); i++)
    {
        arr_2D[0][i]=0;
    }
    for(int i=0; i<=a.size(); i++)
    {
        arr_2D[i][0]=0;
    }

    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[a.size()-i]==b[b.size()-j])
            {
                arr_2D[i][j]=1 + arr_2D[i-1][j-1];
            }
            else
            {
                arr_2D[i][j]=max(arr_2D[i][j-1], arr_2D[i-1][j]);
            }
        }
    }

    int ans=arr_2D[a.size()][b.size()];

    for(int i=0; i<a.size()+1; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int main()
{
    string a;
    cout<<"Enter 1st String: ";
    cin>>a;

    cout<<endl;
    string b;
    cout<<"Enter 2nd String: ";
    cin>>b;

    cout<<endl;
    cout<<"LCS using Brute-Force: "<<LCS(a, b)<<endl;
    cout<<"LCS using Memoization: "<<LCSMem(a, b)<<endl;
    cout<<"LCS using Dynamic Programming: "<<LCSDP(a, b)<<endl;
}
