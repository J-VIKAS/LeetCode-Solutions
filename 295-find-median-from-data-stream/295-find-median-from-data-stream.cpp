class MedianFinder {
public:
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        if ( max_heap.size() - min_heap.size() == 2 ){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if ( max_heap.size() > 0 && min_heap.size() > 0 && max_heap.top() > min_heap.top() ){
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if ( max_heap.size() == min_heap.size() )   return (float)( max_heap.top() + min_heap.top() ) / 2;
        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */