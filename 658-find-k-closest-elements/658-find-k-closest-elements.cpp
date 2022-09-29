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
        int l = ind, r = ind+1;
        while ( l >= 0 && r < n && r-l-1 < k ){
            if ( abs(arr[l]-x) <= abs(arr[r]-x) )  ans.push_back(arr[l--]);
            else ans.push_back(arr[r++]);
        }
        while ( l >= 0 && r-l-1 < k )   ans.push_back(arr[l--]);
        while ( r < n && r-l-1 < k )    ans.push_back(arr[r++]);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};