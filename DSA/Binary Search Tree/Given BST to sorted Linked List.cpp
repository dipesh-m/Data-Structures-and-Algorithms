#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;
    cout<<endl;

    if(rootData==-1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout<<"Enter left child of "<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>* leftChild=new BinaryTreeNode<int>(leftChildData);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData!=-1)
        {
            BinaryTreeNode<int>* rightChild=new BinaryTreeNode<int>(rightChildData);
            front->right=rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class bstToSortedLLReturn
{
public:
    Node* head;
    Node* tail;
};

bstToSortedLLReturn bstToSortedLL(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        bstToSortedLLReturn output;
        output.head=NULL;
        output.tail=NULL;
        return output;
    }

    Node* head=new Node(root->data);

    bstToSortedLLReturn leftOutput=bstToSortedLL(root->left);
    bstToSortedLLReturn rightOutput=bstToSortedLL(root->right);

    if(leftOutput.head!=NULL)
    {
        leftOutput.tail->next=head;
    }

    if(rightOutput.head!=NULL)
    {
        head->next=rightOutput.head;
    }

    bstToSortedLLReturn output;
    if(leftOutput.head==NULL)
    {
        output.head=head;
    }
    else
    {
        output.head=leftOutput.head;
    }

    if(rightOutput.head==NULL)
    {
        output.tail=head;
    }
    else
    {
        output.tail=rightOutput.tail;
    }

    return output;
}

int main()
{
    cout<<"ENTER BST DATA:-\n\n";
    BinaryTreeNode<int>* root=takeInputLevelWise();
    Node* ans=bstToSortedLL(root).head;

    cout<<"\nSORTED LINKED LIST:-\n\n";
    Node* temp=ans;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}
