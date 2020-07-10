#include<iostream>
#include<climits>
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

bool isBST(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }

    if(root->data<min || root->data>max)
    {
        return false;;
    }

    bool isLeftOk=isBST(root->left, min, root->data-1);
    bool isRightOk=isBST(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    if(isBST(root))
    {
        cout<<"\nTrue"<<endl;
    }
    else
    {
        cout<<"\nFalse"<<endl;
    }
}
