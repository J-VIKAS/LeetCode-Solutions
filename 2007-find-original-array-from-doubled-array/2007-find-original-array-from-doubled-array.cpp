class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if ( n%2 != 0 ) return {};
        vector<int> ans;
        sort(changed.begin(), changed.end());
        map<int,int> p;
        for ( int i = 0; i<n; i++ ){
            p[ changed[i] ]++;
        }
        for ( int i = 0; i<n; i++ ){
            if ( p[ changed[i] ] > 0 ){ 
                p[ changed[i] ]--;
                if ( p[ changed[i]*2 ] > 0 ){
                    ans.push_back( changed[i] );
                    p [ changed[i]*2 ]--;
                }
            }
        }
        if ( ans.size() == n/2 ) return ans;
        return {};
    }
};