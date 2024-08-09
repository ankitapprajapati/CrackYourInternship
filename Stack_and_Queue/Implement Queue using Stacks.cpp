class MyQueue {
    stack<int> st1;
    stack<int> st2;
    
public:
    MyQueue() {    
    }
    
    void push(int x) {
        st1.push(x)  ;      
    }
    
    int pop() {
        while( !st1.empty() ){
            st2.push( st1.top());
            st1.pop();
        }
        int popped =st2.top();
        st2.pop();
        while( !st2.empty() ){
            st1.push( st2.top() );
            st2.pop();
        }
        return popped;
    }
    
    int peek() {
        while( !st1.empty() ){
            st2.push( st1.top());
            st1.pop();
        }
        int peeked=st2.top();
        while( !st2.empty() ){
            st1.push( st2.top() );
            st2.pop();
        }
        return peeked;
    }
    
    bool empty() {
        return st1.empty() ;        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */