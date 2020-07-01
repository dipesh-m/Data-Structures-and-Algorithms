#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* insertNodeRecursivelyAt(Node* head, int i, int data)
{
    if(head==NULL)
    {
        if(i==0)
        {
            Node* newNode=new Node(data);
            return newNode;
        }

        return head;
    }

    if(i==0)
    {
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }

    Node* smallerOutput=insertNodeRecursivelyAt(head->next, i-1, data);
    head->next=smallerOutput;

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

    head=insertNodeRecursivelyAt(head, i, data);
    print(head);
}
