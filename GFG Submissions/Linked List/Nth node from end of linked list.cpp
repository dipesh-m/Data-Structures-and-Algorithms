// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/

int getSize(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }

    int i=0;
    while(head!=NULL)
    {
        i++;
        head=head->next;
    }

    return i;
}

int getNthFromLast(Node *head, int n)
{
       if(head==NULL)
       {
           return -1;
       }

       // Your code here
       int size=getSize(head);
       int rem=size-n;
       if(rem<0)
       {
           return -1;
       }
       for(int i=0; i<rem; i++)
       {
           head=head->next;
       }

       return head->data;
}

