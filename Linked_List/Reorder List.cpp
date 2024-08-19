class Solution {

    ListNode* findMiddle( ListNode* head){
        if( !head || !head->next)   return head;
        ListNode* slow = head, *fast=head->next;
        while( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse( ListNode* curr){        
        ListNode* prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void mergeAlter( ListNode* head, ListNode* secHead){
        while( head && secHead ){
            ListNode* temp = head->next;
            head->next = secHead;
            secHead = secHead->next;
            head->next->next = temp;
            head = temp;
        }
    }

public:
    void reorderList(ListNode* head) {

        ListNode* middle = findMiddle(head);
        ListNode* secHead = middle->next;
        middle->next=NULL;

        secHead= reverse(secHead);

        mergeAlter(head,secHead); 
    }
}; 