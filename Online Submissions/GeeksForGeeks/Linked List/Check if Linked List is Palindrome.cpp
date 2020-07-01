#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends

#include<algorithm>
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

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

bool isPalindrome(Node *head)
{
    //Your code here
    if(head==NULL)
    {
        return true;
    }

    int size=getSize(head);
    if(size<=1)
    {
        return true;
    }

    if(size%2!=0)
    {
        string s, k;
        if(size==3)
        {
            s+=to_string(head->data);
        }
        else
        {
            for(int i=0; i<(size/2)-1; i++)
            {
                s+=to_string(head->data);
                head=head->next;
            }
            s+=to_string(head->data);
        }
        head=head->next->next;
        while(head!=NULL)
        {
            k+=to_string(head->data);
            head=head->next;
        }

        std::reverse(s.begin(), s.end());

        return s==k;
    }
    else
    {
        string s, k;
        if(size==2)
        {
            s+=to_string(head->data);
        }
        else
        {
            for(int i=0; i<(size/2)-1; i++)
            {
                s+=to_string(head->data);
                head=head->next;
            }
            s+=to_string(head->data);
        }
        head=head->next;
        while(head!=NULL)
        {
            k+=to_string(head->data);
            head=head->next;
        }

        std::reverse(s.begin(), s.end());

        return s==k;
    }
}

