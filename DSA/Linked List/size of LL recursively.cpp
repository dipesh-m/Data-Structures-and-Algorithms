#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

int sizeRecursively(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }

    int smallerOutput=sizeRecursively(head->next);
    return (smallerOutput+1);
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    int sizeRecLL=sizeRecursively(head);
    print(head);
    cout<<endl<<"Size: "<<sizeRecLL<<endl;
}
