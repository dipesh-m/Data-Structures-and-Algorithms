#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

void printTreeLevelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<": ";
        if(front->left!=NULL)
        {
            cout<<"L"<<front->left->data;
            pendingNodes.push(front->left);
        }

        if(front->right!=NULL)
        {
            cout<<" R"<<front->right->data;
            pendingNodes.push(front->right);
        }

        cout<<endl;
    }
}

BinaryTreeNode<int>* bstFromSortedArr(int* arr, int si, int ei)
{
    if(si>ei)
    {
        return NULL;
    }

    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(arr[mid]);

    BinaryTreeNode<int>* leftNode=bstFromSortedArr(arr, si, mid-1);
    BinaryTreeNode<int>* rightNode=bstFromSortedArr(arr, mid+1, ei);

    root->left=leftNode;
    root->right=rightNode;

    return root;
}

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int>* root=bstFromSortedArr(arr, 0, 6);

    cout<<"BST:-\n\n";
    printTreeLevelWise(root);
}
