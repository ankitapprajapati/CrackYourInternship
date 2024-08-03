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
    void helper( TreeNode* root, map<int,map<int,vector<int>>>& mp, int col,int level ){
        if( !root ) return;
        mp[col][level].push_back(root->val);
        helper(root->left,mp,col-1,level+1);
        helper(root->right,mp,col+1,level+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        vector<vector<int>> ans;

        int col=0; 
        int level=0;
        helper(root,mp,col,level);

        for( auto p: mp ){
            vector<int> arr;
            for( auto q: p.second ){
                sort(q.second.begin(),q.second.end());
                arr.insert(arr.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(arr);
        }
        return ans;           
    }
};