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

    void mapParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parents){
        if(!root) return ;
        if(root->left) parents[root->left]=root;
        if(root->right) parents[root->right]=root;
        mapParents( root->left,parents);
        mapParents( root->right,parents);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }

        unordered_map<TreeNode*,TreeNode*> parents;
        parents[root]=NULL;
        mapParents(root,parents);        

        unordered_set <TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        while(!q.empty() ){

            int size = q.size();
            k--;

            for( int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !(visited.find(node->left) != visited.end() ) ){
                    q.push(node->left);
                    visited.insert(node->left);
                    if(k==0) ans.push_back(node->left->val);
                } 
                if(node->right && !(visited.find(node->right) != visited.end() ) ){
                    q.push(node->right);
                    visited.insert(node->right);
                    if(k==0) ans.push_back(node->right->val);
                } 
                if(parents[node] && !(visited.find(parents[node]) != visited.end() )){
                    q.push(parents[node]);
                    visited.insert(parents[node]);
                    if(k==0) ans.push_back(parents[node]->val);
                }
            } 
            if(k==0) return ans;
        }
        return ans;        
    }
};