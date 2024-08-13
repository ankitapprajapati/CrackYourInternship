class solution {
    
    long long MOD = 1000000007;
    
    long long calcValue(Node* node){
        long long ans=0;
        while(node ){
            ans = (ans * 10 + node->data) %MOD;
            node= node->next;
        }
        return ans;
    }
    
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        return (calcValue(first)*calcValue(second))%MOD;
        
    }
};