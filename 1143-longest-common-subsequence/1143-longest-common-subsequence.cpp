class Solution {
public:
    
    int rec( int i, int j, string &text1, string &text2, int n, int m, vector<vector<int>> &dp ){
        
        if ( i == n || j == m )
            return 0;
        
        if ( dp[i][j] != -1 )
            return dp[i][j];
        
        if ( text1[i] == text2[j] ){
            return dp[i][j] = 1 + rec(i+1,j+1,text1,text2,n,m,dp);
        } else {
            return dp[i][j] = max( rec(i+1,j,text1,text2,n,m,dp), rec(i,j+1,text1,text2,n,m,dp) );
        }
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,text1,text2,n,m,dp);
        
    }
};