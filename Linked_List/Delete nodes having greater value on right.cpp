class Solution
{
    Node* reverse(Node* head){
        if(!head) return head;
        Node* past = nullptr;
        Node* pre = head;
        while(pre){
            Node* future=pre->next;
            pre->next=past;
            past=pre;
            pre=future;
        }
        return past;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        head= reverse(head);
        
        Node* temp=head;
        int greater=temp->data;
        
        while(temp->next){
            
            if( temp->next->data < greater ){
                    temp->next=temp->next->next;
            }else{
                temp=temp->next;
                greater = temp->data;
            }
        }
        
        head=reverse(head);
        
        return head;
    }
};
   
