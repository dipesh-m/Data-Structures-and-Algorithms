#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* insertNodeAt(Node* head, int i, int data)
{
    Node* newNode=new Node(data);

    if(i==0)
    {
        newNode->next=head;
        head=newNode;
        return head;
    }

    Node* temp1=head;
    for(int j=0; j<i-1; j++)
    {
        if(temp1!=NULL)
        {
            temp1=temp1->next;
        }
    }
    if(temp1!=NULL)
    {
        Node* temp2=temp1->next;

        temp1->next=newNode;
        newNode->next=temp2;
    }

    return head;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    cout<<endl<<"Position to insert element at?";
    int i;
    cin>>i;

    cout<<endl<<"Data to insert?";
    int data;
    cin>>data;

    head=insertNodeAt(head, i, data);
    print(head);
}
