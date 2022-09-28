class Solution {
public:
    
    int dp[51][51];
    
    int rec( int s, int e, vector<int> &values ){
        if ( e-s+1 < 3 )    return 0;
        
        if ( dp[s][e] != -1 )   return dp[s][e];
        
        int ans = INT_MAX;
        for ( int i = s+1; i<e; i++ ){
            ans = min(ans, values[s]*values[e]*values[i]
                         + rec(s,i,values) + rec(i,e,values) );
        }
        return dp[s][e] = ans;
        
    }
    
    int minScoreTriangulation(vector<int>& values) {
        
        for ( int i = 0; i<51; i++ ){
            for ( int j = 0; j<51; j++ )    dp[i][j] = -1;
        }
        
        int n = values.size(), ans = INT_MAX;
        for ( int i = 1; i<n-1; i++ ){
            ans = min(ans, values[0]*values[n-1]*values[i]
                         + rec(0,i,values) + rec(i,n-1,values) );
        }
        return ans;
        
    }
};