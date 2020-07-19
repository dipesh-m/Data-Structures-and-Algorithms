#include<iostream>
using namespace std;
#include<string>

int editDistance(string a, string b)
{
    if(a.size()==0 || b.size()==0)
    {
        return max(a.size(), b.size());
    }

    if(a[0]==b[0])
    {
        int x=editDistance(a.substr(1), b.substr(1));
        return x;
    }
    else
    {
        int x=min(editDistance(a.substr(1), b) + 1, min(editDistance(a, b.substr(1)) + 1, editDistance(a.substr(1), b.substr(1)) + 1));
        return x;
    }
}

int editDistanceMemHelper(string a, string b, int** arr_2D)
{
    if(a.size()==0 || b.size()==0)
    {
        return max(a.size(), b.size());
    }

    int m=a.size();
    int n=b.size();

    if(arr_2D[m][n]!=-1)
    {
        return arr_2D[m][n];
    }

    if(a[0]==b[0])
    {
        int x=editDistanceMemHelper(a.substr(1), b.substr(1), arr_2D);
        arr_2D[m][n]=x;
        return arr_2D[m][n];
    }
    else
    {
        int x=min(editDistanceMemHelper(a.substr(1), b, arr_2D) + 1, min(editDistanceMemHelper(a, b.substr(1), arr_2D) + 1, editDistanceMemHelper(a.substr(1), b.substr(1), arr_2D) + 1));
        arr_2D[m][n]=x;
        return arr_2D[m][n];
    }
}

int editDistanceMem(string a, string b)
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

    int ans=editDistanceMemHelper(a, b, arr_2D);

    for(int i=0; i<a.size()+1; i++)
    {
        delete []arr_2D[i];
    }

    delete []arr_2D;

    return ans;
}

int editDistanceDP(string a, string b)
{
    int** arr_2D=new int*[a.size()+1];
    for(int i=0; i<a.size()+1; i++)
    {
        arr_2D[i]=new int[b.size()+1];
    }

    for(int i=0; i<=b.size(); i++)
    {
        arr_2D[0][i]=i;
    }
    for(int i=0; i<=a.size(); i++)
    {
        arr_2D[i][0]=i;
    }

    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[a.size()-i]==b[b.size()-j])
            {
                arr_2D[i][j]=arr_2D[i-1][j-1];
            }
            else
            {
                arr_2D[i][j]=min(arr_2D[i-1][j] + 1, min(arr_2D[i][j-1] + 1, arr_2D[i-1][j-1] + 1));
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
    cout<<"Edit Distance using Brute-Force: "<<editDistance(a, b)<<endl;
    cout<<"Edit Distance using Memoization: "<<editDistanceMem(a, b)<<endl;
    cout<<"Edit Distance using Dynamic Programming: "<<editDistanceDP(a, b)<<endl;
}
