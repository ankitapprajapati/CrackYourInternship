/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        mp[nullptr] = nullptr;

        Node* first = head;
        Node* dummy = new Node(-1);
        Node* second = dummy;

        while( first ){
            second->next = new Node(first->val);
            mp[first]=second->next;

            first = first->next;
            second = second->next;
        }

        first = head;
        second = dummy->next;

        while( first ){
            second->random = mp[first->random];

            first = first->next;
            second = second->next;
        }

        return dummy->next;        
    }
};