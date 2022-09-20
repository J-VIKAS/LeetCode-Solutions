class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        int dp[1001][1001];
        for ( int i = 0; i<1001; i++ ){
            for ( int j = 0; j<1001; j++ )  dp[i][j] = 0;
        }
        for ( int i = n-1; i>=0; i-- ){
            for ( int j = m-1; j>=0; j-- ){
                if ( nums1[i] == nums2[j] )
                    dp[i][j] = dp[i+1][j+1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};