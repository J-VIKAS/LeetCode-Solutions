class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if ( n%2 != 0 ) return {};
        sort(changed.begin(),changed.end());
        vector<int> ans;
        int p[200003] = {0};
        for ( int i = 0; i<n; i++ ){
            p[ changed[i] ]++;
        }
        for ( int i = 0; i<n; i++ ){
            if ( p[ changed[i] ] > 0 ){
                p[ changed[i] ]--;
                if ( p[ changed[i]*2 ] > 0 ){
                    ans.push_back( changed[i] );
                    p [ changed[i]*2 ]--;
                } else {
                    p[ changed[i] ]++;
                }
            }
        }
        if ( ans.size() == n/2 ) return ans;
        return {};
    }
};