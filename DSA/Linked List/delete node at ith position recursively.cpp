#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* deleteNodeRecursivelyAt(Node* head, int d)
{
    if(head==NULL)
    {
        return head;
    }

    if(d==0)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    if(head!=NULL)
    {
        Node* smallOutput=deleteNodeRecursivelyAt(head->next, d-1);
        head->next=smallOutput;
    }

    return head;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    cout<<endl<<"Position of the node to be deleted?";
    int d;
    cin>>d;

    head=deleteNodeRecursivelyAt(head, d);
    print(head);
}
