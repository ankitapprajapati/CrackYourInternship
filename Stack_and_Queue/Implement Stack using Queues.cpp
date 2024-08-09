class MyStack {
public:
    deque<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }
        int t = q.back();
        q.pop_back();
        return t;
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }
        return q.back();
    }
    
    bool empty() {
        if(q.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */