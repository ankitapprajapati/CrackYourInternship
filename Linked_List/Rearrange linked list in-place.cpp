class Solution {
    Node* middle(Node* head ){
        if( !head || !head->next ) return head;
        Node* slow = head;
        Node* fast = head->next;
        
        while( fast && fast->next ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
  public:
    Node *inPlace(Node *root) {
        // Code here
        Node* mid = middle(root);
        
        Node* head2 = mid->next;
        Node* head1 = root;
        
        mid->next = nullptr;
        
        head2 = reverse( head2 );
        
        while( head1 && head2 ){
            Node* next1 = head1->next;
            Node* next2 = head2->next;
            
            head1->next = head2;
            head2->next = next1;
            
            head1 = next1;
            head2 = next2;
            
        }
        
        return root;
        
    }
};