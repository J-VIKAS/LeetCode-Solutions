class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(1001,vector<int>(1001,0));
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