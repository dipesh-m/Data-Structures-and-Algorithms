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

pair<int,int> heightDiameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int, int> leftAns=heightDiameter(root->left);
    pair<int, int> rightAns=heightDiameter(root->right);

    int lh=leftAns.first;
    int ld=leftAns.second;
    int rh=rightAns.first;
    int rd=rightAns.second;

    int height=1+max(lh, rh);
    int diameter=max(lh+rh, max(ld, rd));

    pair<int,int> p;
    p.first=height;
    p.second=diameter;

    return p;
}

int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();

    pair<int,int> p=heightDiameter(root);
    cout<<"\nDiameter of Binary Tree: "<<p.second<<endl;

    delete root;
}
