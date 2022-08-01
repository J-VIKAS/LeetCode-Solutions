class Solution {
public:
        
    long long int rec(int i, int j, int n, int m, vector<vector<long long int>> &dp){
        if ( i == n && j == m ){
            return 1;
        }
        
        if ( dp[i][j] != -1 )
            return dp[i][j];
            
        if ( i == n ){
            return dp[i][j] = rec(i,j+1,n,m,dp);
        } else if ( j == m ){
            return dp[i][j] = rec(i+1,j,n,m,dp);
        } else {
            return dp[i][j] = rec(i+1,j,n,m,dp) + rec(i,j+1,n,m,dp);
        }
    }
    
    int uniquePaths(int m, int n) {
        if (n == 1 && m == 1)
            return 1;
        vector<vector<long long int>> dp(n+1,vector<long long int>(m+1,-1));
        rec(0,0,n,m,dp);
        return dp[1][1];
    }
};