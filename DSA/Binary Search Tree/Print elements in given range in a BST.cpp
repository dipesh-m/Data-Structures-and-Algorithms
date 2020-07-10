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

void printElementsInRange(BinaryTreeNode<int>* root, int x, int y)
{
    if(root==NULL)
    {
        return;
    }

    if(root->data>x && root->data<y)
    {
        cout<<root->data<<" ";
        printElementsInRange(root->left,x,y);
        printElementsInRange(root->right,x,y);
    }
    else if(root->data>=y)
    {
        if(root->data==y)
        {
            cout<<root->data<<" ";
        }

        printElementsInRange(root->left,x,y);
    }
    else
    {
        if(root->data==x)
        {
            cout<<root->data<<" ";
        }

        printElementsInRange(root->right,x,y);
    }
}

int main()
{
    cout<<"ENTER BST DATA:-\n\n";
    BinaryTreeNode<int>* root=takeInputLevelWise();

    cout<<"\nEnter minimum value of range:";
    int x; cin>>x; cout<<endl;
    cout<<"\nEnter maximum value of range:";
    int y; cin>>y; cout<<endl;

    printElementsInRange(root, x, y);
    cout<<endl;
}
