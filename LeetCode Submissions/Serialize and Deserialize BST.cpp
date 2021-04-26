/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void helper(TreeNode* root, string& ans, int k, char p)
    {
        if(root==NULL)
            return;

        for(int i=0; i<k; i++)
            ans+='d';

        if(p!='n')
            ans+=p;

        ans+=to_string(root->val);

        helper(root->left, ans, k+1, 'l');
        helper(root->right, ans, k+1, 'r');
    }

    string serialize(TreeNode* root)
    {
        string ans;
        helper(root, ans, 0, 'n');
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data=="")
            return NULL;

        int i=0, prev=0;
        string x;
        while(i<data.size() && data.at(i)!='d')
        {
            x+=data.at(i);
            i++;
        }

        TreeNode* root=new TreeNode(stoi(x));

        stack<TreeNode*> parents;
        parents.push(root);
        while(i<data.size())
        {
            int dash=0;
            while(data.at(i)=='d')
            {
                dash++;
                i++;
            }

            char p=data.at(i);
            i++;

            string y;
            while(i<data.size() && data.at(i)!='d')
            {
                y+=data.at(i);
                i++;
            }

            TreeNode* parent=NULL;
            if(dash>prev)
            {
                parent=parents.top();

                if(p=='l')
                {
                    parent->left=new TreeNode(stoi(y));
                    parents.push(parent->left);
                }
                else
                {
                    parent->right=new TreeNode(stoi(y));
                    parents.push(parent->right);
                }
            }
            else
            {
                if(dash==prev)
                    parents.pop();
                else
                {
                    while(parents.size()!=dash)
                        parents.pop();
                }

                parent=parents.top();

                parent->right=new TreeNode(stoi(y));
                parents.push(parent->right);
            }

            prev=dash;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
