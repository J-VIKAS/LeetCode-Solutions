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
        
        // cout << "store : ";
        // for ( int i = 0; i<store.size(); i++ ){
        //     cout << "(" << store[i].first << "," << store[i].second << ") ";
        // } cout << "\n";
        // cout << "checking : (" << start << "," << end << ")\n";
        
        if ( !check(start,end) ){
            // cout << "not found pushed it\n\n";
            store.push_back(make_pair(start,end));
            return true;
        }
        // cout << "found\n\n";
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */