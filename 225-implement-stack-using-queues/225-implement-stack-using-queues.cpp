class MyStack {
public:
    
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> p;
        int last = -1;
        while ( q.size() != 1 ){
            last = q.front();
            p.push(last);
            q.pop();
        }
        last = q.front();
        q.pop();
        q = p;
        return last;
    }
    
    int top() {
        queue<int> p;
        int last = -1;
        while ( !q.empty() ){
            last = q.front();
            p.push(last);
            q.pop();
        }
        q = p;
        return last;
    }
    
    bool empty() {
        return q.empty();
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