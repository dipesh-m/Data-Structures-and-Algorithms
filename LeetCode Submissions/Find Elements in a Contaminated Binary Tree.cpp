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
class FindElements {
public:
    unordered_set<int> values;

    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;

        values.insert(root->val);

        if(root->left!=NULL)
            root->left->val=(2*root->val)+1;
        if(root->right!=NULL)
            root->right->val=(2*root->val)+2;

        helper(root->left);
        helper(root->right);
    }

    FindElements(TreeNode* root)
    {
        if(root==NULL)
            return;

        root->val=0;
        helper(root);
    }

    bool find(int target)
    {
        return values.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
