class MyCircularQueue {
public:
    
    vector<int> q;
    int f = 0, r = 0, k;
    
    MyCircularQueue(int k) {
        q.resize(k,-1);
        this->k = k;
    }
    
    bool enQueue(int value) {
        if ( q[r] == -1 ){
            q[r++] = value;
            r = r%k;
            return true;
        } return false;
    }
    
    bool deQueue() {
        if ( q[f] == -1 ) return false;
        else{
            q[f++] = -1;
            f = f%k;
            return true;
        }
    }
    
    int Front() {
        return q[f];
    }
    
    int Rear() {
        if ( r-1 < 0 ) return q[k-1];
        return q[r-1];
    }
    
    bool isEmpty() {
        return q[ (f+1)%k ] == -1 && f == r;
    }
    
    bool isFull() {
        return q[  (f+1)%k ] != -1 && f == r;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */