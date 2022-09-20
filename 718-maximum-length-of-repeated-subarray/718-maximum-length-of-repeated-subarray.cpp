class Solution {
public:
    
    int rec( int i, int j, vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>> &dp ){
        if ( i == n || j == m ) return 0;
        if ( dp[i][j] != -1 ) return dp[i][j];
        if ( nums1[i] == nums2[j] ) return dp[i][j] = 1 + rec(i+1,j+1,nums1,nums2,n,m,dp);
        return dp[i][j] = 0;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( dp[i][j] == -1 )   dp[i][j] = rec(i,j,nums1,nums2,n,m,dp);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};