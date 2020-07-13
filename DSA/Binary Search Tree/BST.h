#include "BinaryTreeNode.h"
using namespace std;

class BST
{
private:
    BinaryTreeNode<int>* root;

public:
    BST()
    {
        root=NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int>* deleteDataHelper(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(data<root->data)
        {
            root->left=deleteDataHelper(data, root->left);
            return root;
        }
        else if(data>root->data)
        {
            root->right=deleteDataHelper(data, root->right);
            return root;
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                BinaryTreeNode<int>* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                BinaryTreeNode<int>* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* minNode=root->right;
                while(minNode->left!=NULL)
                {
                    minNode=minNode->left;
                }

                int minData=minNode->data;
                root->data=minData;

                root->right=deleteDataHelper(minData, root->right);

                return root;
            }
        }
    }

public:
    void deleteData(int data)
    {
        root=deleteDataHelper(data, root);
    }

private:
    BinaryTreeNode<int>* insertDataHelper(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int>* newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data<root->data)
        {
            root->left=insertDataHelper(data, root->left);
        }
        else
        {
            root->right=insertDataHelper(data, root->right);
        }

        return root;
    }

public:
    void insertData(int data)
    {
        root=insertDataHelper(data, root);
    }

private:
    bool hasDataHelper(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->data==data)
        {
            return true;
        }
        else if(data<root->data)
        {
            return hasDataHelper(data, root->left);
        }
        else
        {
            return hasDataHelper(data, root->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasDataHelper(data, root);
    }

private:
    void printTreeHelper(BinaryTreeNode<int>* root)
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

        printTreeHelper(root->left);
        printTreeHelper(root->right);
    }

public:
    void printTree()
    {
        printTreeHelper(root);
    }
};
