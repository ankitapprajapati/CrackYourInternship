class Solution {
    Node* merge(Node* head1 , Node* head2 ){
        
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        while( head1 && head2 ){
            if( head1->data >= head2->data ){
                curr->bottom = head2;
                head2 = head2->bottom;
            }else{
                curr->bottom = head1;
                head1 = head1->bottom;
            }
            curr->next = nullptr;
            curr = curr->bottom;
        }
        if(head1) curr->bottom = head1;
        if(head2) curr->bottom = head2;
        return dummy->bottom;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if ( !root || !root->next ){
            return root;
        }
        
        root->next = flatten( root->next );
            
        root = merge(root, root->next);
        
        return root;
    }
};