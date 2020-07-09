#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data:-"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter number of children of:- "<<front->data<<endl;
        int n;
        cin>>n;

        for(int i=0; i<n; i++)
        {
            int childData;
            cout<<"Enter child number "<<i<<" of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void preOrder(TreeNode<int>* root)
{
    cout<<root->data<<" ";

    for(int i=0; i<root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root)
{
    for(int i=0; i<root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }

    cout<<root->data<<" ";
}

int main()
{
    TreeNode<int>* root=takeInputLevelWise();

    cout<<"\nPre Order Traversal:-\n";
    preOrder(root);
    cout<<endl;

    cout<<"\nPost Order Traversal:-\n";
    postOrder(root);
    cout<<endl;
}
