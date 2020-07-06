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

void printTreeLevelWise(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<endl;
        cout<<front->data<<":";
        for(int i=0; i<front->children.size(); i++)
        {
            if(i==front->children.size()-1)
            {
                cout<<front->children[i]->data;
            }
            else
            {
                cout<<front->children[i]->data<<",";
            }

            pendingNodes.push(front->children[i]);
        }
    }
}

int main()
{
    TreeNode<int>* root=takeInputLevelWise();
    printTreeLevelWise(root);
}
