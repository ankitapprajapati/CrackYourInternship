class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* dummyEven = new Node(-1);
        Node* dummyOdd = new Node(-1);
        Node* odd = dummyOdd;
        Node* even = dummyEven;
        
        while( head ){
            if( head->data&1 ){
                odd->next = head;
                odd=odd->next;
            }else{
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        
        even->next = dummyOdd->next;
        odd->next = NULL;
        
        return dummyEven->next;
    }
};