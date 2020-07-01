// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);

        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


#include<string>
#include<algorithm>

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    if(head->next==NULL || head==NULL)
    {
        return head;
    }

    Node* temp=reverseList(head->next);

    head->next->next=head;
    head->next=NULL;

    return temp;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    if(first==NULL && second==NULL)
    {
        return NULL;
    }

    struct Node* head1=reverseList(first);
    struct Node* head2=reverseList(second);

    struct Node* head=NULL;
    int carry=0;
    while(head1!=NULL || head2!=NULL)
    {
        int sum=carry;
        if(head1!=NULL)
        {
            sum+=head1->data;
        }
        if(head2!=NULL)
        {
            sum+=head2->data;
        }

        if(sum>9)
        {
            carry=sum/10;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }

        struct Node* newNode=new struct Node(sum);
        newNode->next=head;
        head=newNode;

        if(head1!=NULL)
        {
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            head2=head2->next;
        }
    }

    if(carry!=0)
    {
        struct Node* newNode=new struct Node(carry);
        newNode->next=head;
        head=newNode;
    }

    return head;
}
