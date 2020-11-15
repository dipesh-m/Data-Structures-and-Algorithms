#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;

     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;

         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }

        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);

     }

     return(0);

}

// } Driver Code Ends


/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

void PRINT(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct node* reverseLL(struct node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    struct node* smallerOutput=reverseLL(head->next);

    struct node* tail=head->next;
    tail->next=head;
    head->next=NULL;

    return smallerOutput;
}

struct node* reverse (struct node* head, int k)
{
    // Complete this method
    struct node* arr[100]={NULL};
    struct node* temp=head;
    int i=0;

    while(temp!=NULL)
    {
        struct node* here=temp;
        for(int z=0; z<k-1; z++)
        {
            if(temp==NULL)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            struct node* temp1=temp;
            temp=temp->next;
            temp1->next=NULL;
        }

        arr[i]=reverseLL(here);
        PRINT(arr[i]);
        i++;
    }

    return NULL;
}
