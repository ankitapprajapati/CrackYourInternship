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
        if ( root ==NULL ) return NULL;
        if ( root->val == q->val ) return q;
        if ( root->val == p->val ) return p;

        TreeNode* leftValue = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightValue = lowestCommonAncestor(root->right,p,q);

        if( leftValue==NULL && rightValue==NULL ) {return nullptr;}
        else if( leftValue!=NULL && rightValue==NULL ) {return leftValue;}
        else if( leftValue==NULL && rightValue!=NULL ) {return rightValue; }
        else {return root;  }  
    }
};