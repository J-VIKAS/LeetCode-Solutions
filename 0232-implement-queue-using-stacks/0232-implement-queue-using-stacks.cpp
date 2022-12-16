class MyQueue {
public:
    
    stack<int> s;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> k;
        int last = -1;
        while ( s.size() != 1 ){
            last = s.top();
            k.push(last);
            s.pop();
        }
        last = s.top();
        s.pop();
        while ( !k.empty() ){
            s.push(k.top());
            k.pop();
        }
        return last;
    }
    
    int peek() {
        stack<int> k;
        int last = -1;
        while ( !s.empty() ){
            last = s.top();
            k.push(last);
            s.pop();
        }
        while ( !k.empty() ){
            s.push(k.top());
            k.pop();
        }
        return last;
    }
    
    bool empty() {
       return  s.empty();
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