#include<iostream>
using namespace std;
#include "class Node.h"
#include "taking input and printing LL.h"

void printAt(Node* head, int i)
{
    int j=0;
    while(j<i && head!=NULL)
    {
        head=head->next;
        j++;
    }

    if(head!=NULL)
    {
        cout<<head->data<<endl;
    }
}

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

int midOfLLUsingSize(Node* head)
{
    if(head==NULL)
    {
        return INT_MIN;
    }

    int get_size=sizeIteratively(head);
    int mid=(get_size-1)/2;

    return mid;
}

int midOfLLUsing2Ptrs(Node* head)
{
    if(head==NULL)
    {
        return INT_MIN;
    }

    Node* slow=head;
    Node* fast=head->next;
    int mid=0;
    while(fast!=NULL)
    {
        if(fast->next!=NULL)
        {
            fast=fast->next->next;
            mid+=1;
        }
        else
        {
            fast=fast->next;
        }
        slow=slow->next;
    }

    return mid;
}

int main()
{
    cout<<"INSERT THE LL DATA:-"<<endl;
    Node* head=takeInput();

    //for even sized LL, the index 1 less than (size of LL)/2 is treated as mid

    int mid1=midOfLLUsingSize(head);
    if(mid1!=INT_MIN)
    {
        cout<<"Mid of LL Using Size: ";
        printAt(head, mid1);
    }

    cout<<endl;

    int mid2=midOfLLUsing2Ptrs(head);
    if(mid2!=INT_MIN)
    {
        cout<<"Mid of LL Using 2 Pointers: ";
        printAt(head, mid2);
    }
}
