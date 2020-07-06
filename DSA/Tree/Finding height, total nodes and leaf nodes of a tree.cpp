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

int findHeight(TreeNode<int>* root)
{
    int height=0;

    for(int i=0; i<root->children.size(); i++)
    {
        int smallerOutput=findHeight(root->children[i]);
        if(height<smallerOutput)
        {
            height=smallerOutput;
        }
    }

    return height+1 ;
}

int countNodes(TreeNode<int>* root)
{
    int count=0;
    for(int i=0; i<root->children.size(); i++)
    {
        int smallerOutput=countNodes(root->children[i]);
        count+=smallerOutput;
    }

    return count+1;
}

int totalLeafNodes(TreeNode<int>* root)
{
    int count=0;
    if(root->children.size()==0)
    {
        count++;
    }

    for(int i=0; i<root->children.size(); i++)
    {
        count+=totalLeafNodes(root->children[i]);
    }

    return count;
}

int main()
{
    TreeNode<int>* root=takeInputLevelWise();

    cout<<"\n\nHeight of tree: "<<findHeight(root);
    cout<<"\n\nTotal Nodes in the tree: "<<countNodes(root);
    cout<<"\n\nTotal Leaf Nodes in the tree: "<<totalLeafNodes(root)<<endl;
}
