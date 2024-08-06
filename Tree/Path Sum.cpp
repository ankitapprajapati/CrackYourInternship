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
    bool check( TreeNode* root, int& targetSum, int sum){
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right && targetSum==sum) {
            return true;            
        }
        return check(root->left,targetSum,sum) ||check(root->right,targetSum,sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return check(root,targetSum,0);                
    }
};