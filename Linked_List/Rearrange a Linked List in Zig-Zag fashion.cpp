Node* zigZag(Node* head) {
        // your code goes here
        if ( !head || !head->next ) return head;
        
        Node* curr = head;
        
        while ( curr && curr->next){
            if( curr->next->next ){
                if( curr->data >= curr->next->data && curr->data >= curr->next->next->data ){
                    int large = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = large;
                }if( curr->next->next->data >= curr->next->data && curr->data <= curr->next->next->data ){
                    int large = curr->next->next->data;
                    curr->next->next->data = curr->next->data;
                    curr->next->data = large;
                }
            }else{
                if( curr->data > curr->next->data ){
                    int large = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = large;
                }
            }
            curr=curr->next->next;
        }
        return head;
        
    }