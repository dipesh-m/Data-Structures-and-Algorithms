#include<iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter data:-"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of children of:- "<<rootData<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        TreeNode<int>* child=takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<":";
    for(int i=0; i<root->children.size(); i++)
    {
        if(i==root->children.size()-1)
        {
            cout<<root->children[i]->data;
        }
        else
        {
            cout<<root->children[i]->data<<",";
        }
    }

    cout<<endl;

    for(int i=0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int>* root=takeInput();
    printTree(root);
}
