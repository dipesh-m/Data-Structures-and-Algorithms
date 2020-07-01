#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

Node* merge2SortedLLs(Node* head1, Node* head2)
{
    Node* head3=NULL;
    Node* tail3=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data <= head2->data)
        {
            if(head3==NULL)
            {
                head3=head1;
                tail3=head1;
            }
            else
            {
                tail3->next=head1;
                tail3=head1;
            }

            head1=head1->next;
        }
        else
        {
            if(head3==NULL)
            {
                head3=head2;
                tail3=head2;
            }
            else
            {
                tail3->next=head2;
                tail3=head2;
            }

            head2=head2->next;
        }
    }

    while(head1!=NULL)
    {
        tail3->next=head1;
        tail3=head1;
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        tail3->next=head2;
        tail3=head2;
        head2=head2->next;
    }

    return head3;
}

int main()
{
    cout<<"INSERT SORTED DATA IN ASCENDING ORDER FOR LL 1:-"<<endl;
    Node* head1=takeInput();

    cout<<endl<<"INSERT SORTED DATA IN ASCENDING ORDER FOR LL 2:-"<<endl;
    Node* head2=takeInput();

    Node* head3=merge2SortedLLs(head1, head2);
    print(head3);
}
