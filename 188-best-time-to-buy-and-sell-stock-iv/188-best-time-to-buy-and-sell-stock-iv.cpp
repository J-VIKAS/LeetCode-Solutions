class Solution {
public:
    
    int rec ( int i, vector<vector<int>> &max_profit_right, int k, int n, vector<vector<int>> &dp ){
        
        if ( i == n || k == 0 ){
            return dp[n][k] = 0;
        }
        
        if ( dp[i][k] != -1 ){
            return dp[i][k];
        }
        
        int ans = 0;
        for ( int j = i; j<n; j++ ){
            ans = max( ans, max_profit_right[j][i] + rec(j+1,max_profit_right,k-1,n,dp) );
        }
        
        return dp[i][k] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        vector<vector<int>> max_profit_right(n,vector<int>(n,0));
        for ( int i = n-1; i>=0; i-- ){
            int Max = prices[i];
            for ( int j = i-1; j>=0; j-- ){
                Max = max(Max,prices[j]);
                max_profit_right[i][j] = max(max_profit_right[i][j+1],Max-prices[j]);
            }
        }
        
        if ( k == 0 ) return 0;
        
        int ans = 0;
        for ( int i = 0; i<n; i++ ){
            ans = max( ans, max_profit_right[i][0] + rec(i+1,max_profit_right,k-1,n,dp) );
        }
        
        return ans;
    }
};