#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* removeTheAdjacentDuplicates(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }

    Node* temp1=head;
    Node* temp2=head->next;

    while(temp2!=NULL)
    {
        if(temp2->data == temp1->data)
        {
            temp1->next=temp2->next;
            temp2=temp1->next;
        }
        else
        {
            temp2=temp2->next;
            temp1=temp1->next;
        }
    }

    return head;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    head=removeTheAdjacentDuplicates(head);
    print(head);
}
