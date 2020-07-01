#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends




/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* h1, Node* h2)
{
    // code here
    Node* h3=NULL;
    Node* t3=NULL;

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<=h2->data)
        {
            if(h3==NULL)
            {
                h3=h1;
                t3=h1;
            }
            else
            {
                t3->next=h1;
                t3=h1;
            }

            h1=h1->next;
        }
        else
        {
            if(h3==NULL)
            {
                h3=h2;
                t3=h2;
            }
            else
            {
                t3->next=h2;
                t3=h2;
            }

            h2=h2->next;
        }
    }

    while(h1!=NULL)
    {
        t3->next=h1;
        t3=h1;
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        t3->next=h2;
        t3=h2;
        h2=h2->next;
    }

    return h3;
}
