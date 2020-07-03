#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

int midOfLLUsing2Ptrs(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;
    int mid=0;
    while(fast!=NULL)
    {
        if(fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            mid+=1;
        }
        else
        {
            fast=fast->next;
        }
    }

    return mid;
}

Node* midAddress(Node* head)
{
    int mid=midOfLLUsing2Ptrs(head);
    int j=0;
    while(j<mid)
    {
        head=head->next;
        j++;
    }

    return head;
}

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

Node* mergeSort(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* m=midAddress(head);

    Node* temp=m->next;
    m->next=NULL;

    Node* a=mergeSort(head);
    Node* b=mergeSort(temp);

    head=merge2SortedLLs(a, b);
    return head;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    head=mergeSort(head);
    print(head);
}
