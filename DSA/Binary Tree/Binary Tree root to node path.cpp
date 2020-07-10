#include<iostream>
#include<climits>
#include<vector>
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

vector<int>* rootToNodePath(BinaryTreeNode<int>* root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==x)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput=rootToNodePath(root->left, x);
    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput=rootToNodePath(root->right, x);
    if(rightOutput!=NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();

    cout<<"\nENTER THE NODE: ";
    int x;
    cin>>x;
    vector<int>* ans=rootToNodePath(root, x);

    if(ans==NULL)
    {
        cout<<"\nNO PATH FOUND";
    }
    else
    {
        for(int i=ans->size()-1; i>=0; i--)
        {
            cout<<ans->at(i)<<" ";
        }
    }

    cout<<endl;

    delete root;
    delete ans;
}
