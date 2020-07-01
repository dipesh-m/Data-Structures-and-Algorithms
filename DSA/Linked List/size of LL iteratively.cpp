#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

int sizeIteratively(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }

    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }

    return c;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    int sizeLL=sizeIteratively(head);
    print(head);
    cout<<endl<<"Size: "<<sizeLL<<endl;
}
