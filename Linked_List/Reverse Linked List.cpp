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
   
public:
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;
        ListNode *past=NULL,*present=head;
        while(present){
            ListNode *future=present->next;
            present->next=past;
            past=present;
            present=future;
        }
        return past;
    }

};
