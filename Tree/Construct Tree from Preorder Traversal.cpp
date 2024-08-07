
Node* construct( int n, int pre[], char preLN[], int& index){
    if( index>=n){
        return nullptr;
    }
    Node* root = new Node(pre[index]);
    
    if(preLN[index]=='N'){
        index++;
        root->left=construct( n, pre, preLN, index);
        index++;
        root->right=construct( n, pre, preLN, index);
    }
    return root;
}


struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index=0;
    Node* root = construct( n, pre, preLN, index);
    return root;
}