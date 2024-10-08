/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;
        if( root->val > q->val && root->val < p->val || root->val < q->val && root->val > p->val ) return root;
        return (root->val > q->val && root->val > p->val)? lowestCommonAncestor(root->left,p,q):lowestCommonAncestor(root->right,p,q);
    }
};