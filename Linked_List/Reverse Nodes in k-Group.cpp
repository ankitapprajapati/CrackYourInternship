/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    bool isPossible ( ListNode* head, int k ){
        int count =0; 
        while( head ){
            count++;
            if(count == k){
                return true;
            }
            head = head->next;
        }
        return false;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        int count=0;
         
        ListNode* temp = dummy;
        ListNode* curr = head;

        bool possible =  isPossible( curr , k);
        if( !possible ) return curr;

        while( curr && count<k ){
            
            ListNode* next = temp->next;

            temp->next = curr;
            curr = curr->next;

            temp->next->next = next;

            
            count++;
        }
        
        if( curr ){
            head->next = reverseKGroup(curr,k);
        }
        return dummy->next;
    }
};