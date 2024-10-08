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
private:
    // TWO POINTER APPROCH
    ListNode* middle(ListNode* head){

        if (!head)  return head;

        ListNode *slow=head,*fast=head;
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }     
        return slow;
    }
public:
    ListNode* middleNode(ListNode* head) {
        // TWO POINTER APPROCH
        return middle(head);
    }
};