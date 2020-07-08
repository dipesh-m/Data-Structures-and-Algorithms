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

void preOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();

    cout<<"\nPre Order Traversal:-\n";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"\nIn Order Traversal:-\n";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"\nPost Order Traversal:-\n";
    postOrderTraversal(root);
    cout<<endl;

    delete root;
}
