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
    void helper(TreeNode* root, string& ans)
    {
        if(root==NULL)
        {
            ans+='#';
            return;
        }

        ans+=to_string(root->val)+',';

        helper(root->left, ans);
        helper(root->right, ans);
    }

    string serialize(TreeNode* root)
    {
        string ans;
        helper(root, ans);
        return ans;
    }

    TreeNode* deHelper(string& data, int& i)
    {
        if(i>=data.size())
            return NULL;

        if(data.at(i)=='#')
        {
            i++;
            return NULL;
        }

        string x;
        while(data.at(i)!=',')
        {
            x+=data.at(i);
            i++;
        }

        i++;

        TreeNode* root=new TreeNode(stoi(x));
        root->left=deHelper(data, i);
        root->right=deHelper(data, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int i=0;
        return deHelper(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
