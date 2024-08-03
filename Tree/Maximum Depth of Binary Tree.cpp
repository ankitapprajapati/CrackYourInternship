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
    int maxi=0;
    void depth( TreeNode* root, int level){
        if(!root) return ;
        maxi=max(maxi,level+1);
        depth(root->left,level+1);
        depth( root->right,level+1);        
    }
public:
    int maxDepth(TreeNode* root) {
        if( root==nullptr ) return 0;
        depth(root,0);
        return maxi;
    }
};