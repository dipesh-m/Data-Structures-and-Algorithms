#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* deleteNodeAt(Node* head, int d)
{
    Node* temp1=head;
    if(d==0)
    {
        head=head->next;
        delete temp1;
        return head;
    }

    for(int j=0; j<d-1; j++)
    {
        if(temp1!=NULL)
        {
            temp1=temp1->next;
        }
    }
    if(temp1!=NULL && temp1->next!=NULL)
    {
        Node* temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
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

    head=deleteNodeAt(head, d);
    print(head);
}
