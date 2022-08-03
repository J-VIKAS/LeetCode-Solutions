class MyCalendar {
public:
    
    vector<pair<int,int>> store;
    
    MyCalendar() {
        
    }
    
    bool check(int start, int end){
        for ( int i = 0; i<store.size(); i++ ){
            if ( store[i].first <= start && store[i].second > start ){
                return true;
            }
            if ( store[i].first < end && store[i].second >= end ){
                return true;
            }
            if ( store[i].first >= start && store[i].second <= end ){
                return true;
            }
        }
        return false;
    }
    
    bool book(int start, int end) {
        
        if ( !check(start,end) ){
            store.push_back(make_pair(start,end));
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */