class MinStack {
public:
    stack<pair<int,int>> s;
    int Min;
    int size = 0;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if ( size == 0 ){
            s.push({val,Min = val});
        } else {
            s.push({val,Min = min(s.top().second,val)});
        } size++;
    }
    
    void pop() {
        s.pop();
        size--;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */