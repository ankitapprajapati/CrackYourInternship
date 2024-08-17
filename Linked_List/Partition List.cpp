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

public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummyLow = new ListNode(0);
        ListNode* dummyHigh = new ListNode(0);

        ListNode* curLow = dummyLow;
        ListNode* curHigh = dummyHigh;

  
        while (head) {
            if (head->val < x) {
                curLow->next = head;
                curLow = curLow->next;
            } else {
                curHigh->next = head;
                curHigh = curHigh->next;
            }
            head = head->next;
        }


        curHigh->next = nullptr;

        curLow->next = dummyHigh->next;

        return dummyLow->next;
    }
};