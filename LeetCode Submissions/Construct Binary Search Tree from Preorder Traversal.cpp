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


 //O(n^2) soln. for worst case

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int si, int ei)
    {
        if(si>ei)
            return NULL;

        TreeNode* root=new TreeNode(preorder.at(si));

        int ls=-1, le=-1;
        if(si+1<=ei && preorder.at(si+1)<preorder.at(si))
        {
            ls=si+1, le=si+1;
            while(le+1<=ei && preorder.at(le+1)<preorder.at(si))
                le++;

            root->left=helper(preorder, ls, le);
        }


        if(ls!=-1 && le<ei)
        {
            int rs=le+1;
            root->right=helper(preorder, rs, ei);
        }
        else if(le<ei && si+1<=ei)
        {
            int rs=si+1;
            root->right=helper(preorder, rs, ei);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        return helper(preorder, 0, preorder.size()-1);
    }
};

/*O(n) soln

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
    TreeNode* helper(vector<int>& preorder, int& i, int p_val)
    {
        if(i==preorder.size() || preorder.at(i)>p_val)
            return NULL;

        TreeNode* root=new TreeNode(preorder.at(i));
        i++;
        root->left=helper(preorder, i, root->val);
        root->right=helper(preorder, i, p_val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int i=0;
        return helper(preorder, i, INT_MAX);
    }
};
