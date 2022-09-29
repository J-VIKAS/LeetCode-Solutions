class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size(), ind = 0, diff = INT_MAX;
        for ( int i = 0; i<n; i++ ){
            if ( diff > abs(arr[i]-x) ){
                ind = i;
                diff = abs(arr[i]-x);
            }
        }
        
        vector<int> ans;
        deque<int> q;
        int l = ind, r = ind+1;
        while ( l >= 0 && r < n && r-l-1 < k ){
            if ( abs(arr[l]-x) <= abs(arr[r]-x) )  q.push_front(arr[l--]);
            else q.push_back(arr[r++]);
        }
        while ( l >= 0 && r-l-1 < k ){
            q.push_front(arr[l--]);
        }
        while ( r < n && r-l-1 < k ){
            q.push_back(arr[r++]);
        }
        while ( !q.empty() ){
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
        
    }
};