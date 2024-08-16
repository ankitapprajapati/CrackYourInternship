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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp =dummy;
        while( l1 && l2 ){
            if( l1->val < l2->val ){
                temp->next=l1;
                l1 = l1->next;
            }else{
                temp->next=l2;
                l2 = l2->next;
            }
        temp = temp->next;
        }
        if( l1 ) temp->next=l1;
        if( l2 ) temp->next=l2;
        return dummy->next;
    }

    ListNode* findMid( ListNode* head ){
        if( !head || !head->next ) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if( !head || !head->next ) {
            return head;
        }   
        ListNode* mid = findMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next=nullptr;

        leftHead = sortList( leftHead );
        rightHead = sortList( rightHead );

        return mergeTwoLists(leftHead,rightHead);
    }
};