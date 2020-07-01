#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int maxPathSumHelper(Node* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }

    int a=maxPathSumHelper(root->left);
    int b=maxPathSumHelper(root->right);

    return root->data+max(a, b);
}

int maxPathSum(Node* root)
{
    // code here
    if(root==NULL)
    {
        return INT_MIN;
    }

    int option1=maxPathSum(root->left);
    int option2=maxPathSum(root->right);

    if(root->left==NULL)
    {
        return option2;
    }

    if(root->right==NULL)
    {
        return option1;
    }

    int lst=maxPathSumHelper(root->left);
    int rst=maxPathSumHelper(root->right);
    int option3=(root->data)+lst+rst;

    return max(max(option1, option2), option3);
}
