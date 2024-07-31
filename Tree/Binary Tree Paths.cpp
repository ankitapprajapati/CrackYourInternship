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
    void helper(TreeNode* root, vector<string> &paths, string st){
        if(root==NULL) return ;
        st+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            paths.push_back(st);
        }else{
            st+="->";
            helper(root->left,paths,st);
            helper(root->right,paths,st);
        }        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;

        string st="";
        helper(root,paths,st);
        return paths;        
    }
};