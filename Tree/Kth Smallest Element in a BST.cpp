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
    void helper(TreeNode* root, int& k,int& ans, int &count){
        if( !root ) return ;
        helper(root->left,k,ans,count);

        if(ans!=-1) return ;
        count++;
        if(count==k) {
            ans=root->val;
            return;
        }
        helper(root->right,k,ans,count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int count=0;
        helper(root,k,ans,count);
        return ans;       
    }
};