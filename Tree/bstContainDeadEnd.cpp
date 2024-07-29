class Solution{
    set<int> st;
    bool checkDeadEnd(Node *root){
        if(!root) return false;
        if(!root->left && !root->right){
            if(st.find(root->data+1)!=st.end() && st.find(root->data-1)!=st.end() ){
                return true;
            }
        }
        st.insert(root->data);
        return isDeadEnd(root->left)||isDeadEnd(root->right);
    }
    
  public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        st.insert(0);
        return checkDeadEnd(root);
    }
};