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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify the code
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Traverse both lists until one of them is exhausted
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // If one of the lists is not exhausted, append the remaining elements
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        // Save the merged list and delete the dummy node
        ListNode* mergedList = dummy->next;
        delete dummy;

        return mergedList;
    }
};
