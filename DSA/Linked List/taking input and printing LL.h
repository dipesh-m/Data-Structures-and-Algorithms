#include "class Node.h"

Node* takeInput()
{
    int data;
    cin>>data;

    Node* head=NULL;
    Node* tail=NULL;

    //takes input until input data is -1...this means this LL implementation can't take -1 as valid input data for LL
    while(data!=-1)
    {
        Node* newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }

        cin>>data;
    }

    return head;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
