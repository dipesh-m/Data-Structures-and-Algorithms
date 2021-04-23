/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s)
    {
        stack<TreeNode*> parents;

        int i=0, prev=0;

        string x;
        while(i<s.size() && s.at(i)!='-')
        {
            x+=s.at(i);
            i++;
        }

        TreeNode* root=new TreeNode(stoi(x));
        parents.push(root);

        while(i<s.size())
        {
            int dash=0;
            while(s.at(i)=='-')
            {
                dash++;
                i++;
            }

            string y;
            while(i<s.size() && s.at(i)!='-')
            {
                y+=s.at(i);
                i++;
            }

            TreeNode* parent=NULL;
            if(prev<dash)
            {
                parent=parents.top();

                parent->left=new TreeNode(stoi(y));
                parents.push(parent->left);
            }
            else
            {
                if(prev==dash)
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
