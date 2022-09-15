class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), i = 0;
        if ( n%2 != 0 ) return {};
        vector<int> ans;
        int p[200003] = {0};
        for ( int i = 0; i<n; i++ )
            p[ changed[i] ]++;
        while ( i <= 100000 ) {
            if ( p[ i ] > 0 ){
                p[ i ]--;
                if ( p[ i*2 ] > 0 ){
                    ans.push_back( i );
                    p [ i*2 ]--;
                } else {
                    p[ i ]++;
                    i++;
                }
            } else {
                i++;
            }
        }
        if ( ans.size() == n/2 ) return ans;
        return {};
    }
};