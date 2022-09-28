class Solution {
public:
    
    int n, m;
    int dp[501][501];
    
    int rec( int i, int j, string &word1, string &word2 ){
        if ( i == n && j == m )   return 0;
        else if ( j == m )  return n-i;
        else if ( i == n ) return m-j;
        if ( dp[i][j] != -1 )   return dp[i][j];
        if ( word1[i] == word2[j] ) return dp[i][j] = rec(i+1,j+1,word1,word2);
        return dp[i][j] = 1 + min( { rec(i+1,j,word1,word2), rec(i,j+1,word1,word2),
                      rec(i,j+1,word1,word2), rec(i+1,j,word1,word2),
                      rec(i+1,j+1,word1,word2) } );
    }
    
    int minDistance(string word1, string word2) {
        
        for ( int i = 0; i<501; i++ ){
            for ( int j = 0; j<501; j++ )   dp[i][j] = -1;
        }
        
        n = word1.size(), m = word2.size();
        return rec(0,0,word1,word2);
    }
};