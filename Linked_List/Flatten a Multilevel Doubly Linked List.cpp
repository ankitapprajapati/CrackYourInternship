/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* solve(Node* head){

        Node* curr = head;
        Node* last = head;

        while( curr ){
            Node* next = curr->next;

            if ( curr->child ){

                Node* childLast = solve (curr->child);

                curr->next = curr->child;
                curr->child->prev = curr;
                
                if(next){
                    childLast->next=next;
                    next->prev=childLast;
                }

                curr->child=nullptr;

                last = childLast;
            }else{
                last=curr;
            }
            curr = next;                
        }
        return last;
    }
    
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        solve(head)  ;
        return head;     
    }
};