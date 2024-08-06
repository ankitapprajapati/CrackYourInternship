class Solution {
public:
    void solve(TreeNode* root, int &prev,int &mini){
        if(!root) return ;
        solve(root->left,prev,mini);
        if(prev != -1){
            mini = min(mini,root->val-prev);
        }
        prev = root->val;
        solve(root->right,prev,mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        solve(root,prev,ans);
        return ans;
    }
};