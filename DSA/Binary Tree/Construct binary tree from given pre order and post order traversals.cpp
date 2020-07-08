#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
    if(inS>inE)
    {
        return NULL;
    }

    int rootData=pre[preS];
    int rootIndex=-1;
    for(int i=inS; i<=inE; i++)
    {
        if(in[i]==rootData)
        {
            rootIndex=i;
            break;
        }
    }

    int lInS=inS;
    int lInE=rootIndex-1;
    int rInS=rootIndex+1;
    int rInE=inE;

    int lPreS=preS+1;
    int lPreE=lInE-lInS+lPreS;
    int rPreS=lPreE+1;
    int rPreE=preE;

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right=buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);

    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size)
{
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

void printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<": ";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<" R"<<root->right->data;
    }
    cout<<endl;

    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};

    BinaryTreeNode<int>* root=buildTree(in, pre, 9);

    cout<<"Binary Tree:- \n\n";
    printTree(root);
    cout<<endl;

    delete root;
}
