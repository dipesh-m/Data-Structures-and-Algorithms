#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* reverseLL(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* smallerOutput=reverseLL(head->next);

    Node* tail=head->next;
    tail->next=head;
    head->next=NULL;

    return smallerOutput;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    head=reverseLL(head);
    print(head);
}
