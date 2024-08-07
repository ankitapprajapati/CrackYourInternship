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
    TreeNode* findPred( TreeNode* root ){
        while(root->right){
            root = root->right;
        }
        return root;
    }

public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;
        
        while( curr ) {
            if( curr->left){
                TreeNode* node = findPred(curr->left);
                node->right = curr->right;
                curr->right=curr->left;
                curr->left= NULL;
            }
            curr = curr->right;
        } 
    }
};