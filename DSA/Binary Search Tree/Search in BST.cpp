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

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int>* root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(x==root->data)
    {
        return root;
    }
    else if(x<root->data)
    {
        return searchInBST(root->left, x);
    }
    else
    {
        return searchInBST(root->right, x);
    }
}

int main()
{
    cout<<"ENTER BST DATA:-\n\n";
    BinaryTreeNode<int>* root=takeInputLevelWise();

    cout<<"\nEnter the element to be searched: ";
    int x;
    cin>>x;
    BinaryTreeNode<int>* ans=searchInBST(root, x);

    if(ans!=NULL)
    {
        cout<<"\nELEMENT FOUND\n";
    }
    else
    {
        cout<<"\nELEMENT NOT FOUND\n";
    }
}
