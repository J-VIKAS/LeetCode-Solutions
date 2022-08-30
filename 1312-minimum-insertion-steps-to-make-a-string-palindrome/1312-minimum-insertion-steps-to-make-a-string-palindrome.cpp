class Solution {
public:
    
    int rec(int i, int j, string &s, string &rs, int n, vector<vector<int>> &dp){
        if ( i == n || j == n )
            return 0;
        
        if ( dp[i][j] != -1 )
            return dp[i][j];
        
        if ( s[i] == rs[j] ){
            return dp[i][j] = 1 + rec(i+1,j+1,s,rs,n,dp);
        } else {
            return dp[i][j] = max( rec(i+1,j,s,rs,n,dp), rec(i,j+1,s,rs,n,dp) );
        }
    }
    
    int minInsertions(string s) {
        
        int n = s.size();
        string rev = "";
        for ( int i = n-1; i>=0; i-- ){
            rev += s[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n - rec(0,0,s,rev,n,dp);
        
    }
};