#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool comparatorForSortingInput(Edge e1, Edge e2)
{
    return (e1.weight<e2.weight);
}

bool unionFind(Edge e, int* parents)
{
    int parentSource=e.source;
    while(parents[parentSource]!=parentSource)
    {
        parentSource=parents[parentSource];
    }

    int parentDest=e.dest;
    while(parents[parentDest]!=parentDest)
    {
        parentDest=parents[parentDest];
    }

    if(parentSource==parentDest)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void kruskals(Edge* input, int n, int e)
{
    sort(input, input+e, comparatorForSortingInput);

    Edge* output=new Edge[n-1];

    int* parents=new int[n];
    for(int i=0; i<n; i++)
    {
        parents[i]=i;
    }

    int _count=0, inputIndex=0, outputIndex=0;
    while(_count<n-1)
    {
        bool toTake=unionFind(input[inputIndex], parents);

        if(toTake==true)
        {
            output[outputIndex]=input[inputIndex];

            int p1=input[inputIndex].source;
            int p2=input[inputIndex].dest;
            parents[p2]=p1;

            outputIndex++;
            _count++;
        }

        inputIndex++;
    }

    int weightMST=0;
    cout<<"MST:-"<<endl;
    for(int i=0; i<n-1; i++)
    {
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;

        weightMST+=output[i].weight;
    }

    cout<<"\nTOTAL WEIGHT OF MST = "<<weightMST<<endl;

    delete []output;
    delete []parents;
}

int main()
{
    cout<<"ENTER NUMBER OF VERTICES: ";
    int n;
    cin>>n;
    cout<<endl;

    cout<<"ENTER NUMBER OF EDGES: ";
    int e;
    cin>>e;
    cout<<endl;

    Edge* input=new Edge[e];
    cout<<"ENTER "<<e<<" EDGES IN FORMAT: SOURCE DESTINATION WEIGHT"<<endl;
    for(int i=0; i<e; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;

        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    cout<<endl;

    kruskals(input, n, e);

    delete []input;
}
