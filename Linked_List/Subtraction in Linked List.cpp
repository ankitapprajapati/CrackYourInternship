class Solution {

int length(Node* root) {
    int len = 0;
    while (root) {
        len++;
        root = root->next;
    }
    return len;
}

bool isHead1Larger(Node* head1, Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    if (len1 > len2) return true;
    if (len1 < len2) return false;

    while (head1 && head2) {
        if (head1->data > head2->data) return true;
        if (head1->data < head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return false;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

Node* calculate(Node* larger, Node* smaller) {
    if (!smaller) return larger;

    larger = reverse(larger);
    smaller = reverse(smaller);

    Node* result = larger;
    int borrow = 0;

    while (smaller) {
        int largerValue = larger->data - borrow;
        int smallerValue = smaller->data;

        if (largerValue < smallerValue) {
            largerValue += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        larger->data = largerValue - smallerValue;

        smaller = smaller->next;
        larger = larger->next;
    }

    while (larger && borrow) {
        int largerValue = larger->data - borrow;

        if (largerValue < 0) {
            largerValue += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        larger->data = largerValue;
        larger = larger->next;
    }

    result = reverse(result);

    while (result && result->data == 0) result = result->next;

    return (result) ? result : new Node(0);
}

public:
Node* subLinkedList(Node* head1, Node* head2) {
    while (head1 && head1->data == 0) head1 = head1->next;
    while (head2 && head2->data == 0) head2 = head2->next;

    if (!head1 && !head2) return new Node(0);
    if (!head1) return reverse(copyList(head2));
    if (!head2) return reverse(copyList(head1));

    Node* larger = isHead1Larger(head1, head2) ? head1 : head2;
    Node* smaller = larger == head1 ? head2 : head1;

    Node* result = calculate(larger, smaller);

    return result;
}

// Helper function to create a copy of the linked list
Node* copyList(Node* head) {
    Node* newHead = nullptr;
    Node* tail = nullptr;
    while (head) {
        Node* newNode = new Node(head->data);
        if (!newHead) {
            newHead = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        head = head->next;
    }
    return newHead;
}

};