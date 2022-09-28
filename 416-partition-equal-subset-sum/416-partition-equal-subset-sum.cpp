class Solution {
public:
    
    int n, sum = 0, dp[201][20001];
    int rec( int i, vector<int> &nums, int curr_sum ){
        if ( i == n ){
            if ( curr_sum == sum/2 ) return 1;
            else return 0;
        }
        if ( dp[i][curr_sum] != -1 )    return dp[i][curr_sum];
        return dp[i][curr_sum] = rec(i+1,nums,curr_sum+nums[i]) || rec(i+1,nums,curr_sum);
    }
    
    bool canPartition(vector<int>& nums) {
        
        for ( int i = 0; i<201; i++ )
            for ( int j = 0; j<20001; j++ ) dp[i][j] = -1;
        
        sum = 0, n = nums.size();
        for ( int i = 0; i<n; i++ ) sum += nums[i];
        if ( sum%2 != 0 )   return false;
        return rec(0,nums,0);
        
    }
};