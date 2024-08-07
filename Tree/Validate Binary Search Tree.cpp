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
    bool validate( TreeNode* root, long mini, long maxi ){
        if( !root ) return true;
        else if(root->val <= mini || root->val >= maxi ) return false;
        return validate(root->left,mini, root->val ) && validate(root->right, root->val, maxi );
    }
public:
    bool isValidBST(TreeNode* root) {
        long mini= LONG_MIN;
        long maxi= LONG_MAX;
        return validate(root,mini,maxi);        
    }
};