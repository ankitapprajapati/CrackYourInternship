class LRUCache {
public:
    int mSize;
    int mCapacity;
    class Node {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v, Node *p, Node *n) {
            key = k;
            val = v;
            prev = p;
            next = n;
        };
    };
    Node *mHead;
    Node *mTail;
    unordered_map<int, Node*> mMap;

    LRUCache(int capacity) {
        mCapacity = capacity;
        mSize = 0;
        mHead = new Node(-1, -1, NULL, NULL);
        mTail = new Node(-1, -1, NULL, NULL);
        mTail->prev = mHead;
        mHead->next = mTail;
    }
    
    int get(int key) {
        if(mMap.find(key) == mMap.end())
            return -1;
        Node *curNode = mMap[key];
        deleteNode(curNode);
        addNode(curNode);
        return curNode->val;
    }
    
    void put(int key, int value) {

        if(mMap.find(key) != mMap.end()) {
            mMap[key]->val = value;
            deleteNode(mMap[key]);
            addNode(mMap[key]);
        } else {
            if(mSize<mCapacity) {
                Node *newNode = new Node(key, value, NULL, NULL);
                addNode(newNode);
                mMap[key] = newNode;
                mSize++;
            } else {
                Node *delNode = mHead->next;
                deleteNode(delNode);
                mMap.erase(delNode->key);
                Node *newNode = new Node(key, value, NULL, NULL);             
                addNode(newNode);
                mMap[key] = newNode;
            }
        }
    }

    void addNode(Node *curNode) {
        Node *last = mTail->prev;
        last->next = curNode;
        curNode->prev = last;
        curNode->next = mTail;
        mTail->prev = curNode;
    }

    void deleteNode(Node *curNode) {
       Node *nextNode = curNode->next;
       Node *prevNode = curNode->prev;
       prevNode->next = nextNode;
       nextNode->prev = prevNode;
       curNode->next = NULL;
       curNode->prev = NULL;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */