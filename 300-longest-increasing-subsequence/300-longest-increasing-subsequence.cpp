class Solution {
public:
    
    int rec(int i, int p, vector<int> &nums, int n, vector<vector<int>> &dp){
        
        if ( i == n+1 ){
            return 0;
        }
        
        if ( dp[i][p] != -1 ){
            return dp[i][p]; 
        }
        
        if ( p == 0 || ( nums[i-1] > nums[p-1] ) ){
            return dp[i][p] = max( 1 + rec(i+1,i,nums,n,dp), rec(i+1,p,nums,n,dp) );
        } else {
            return dp[i][p] = rec(i+1,p,nums,n,dp);
        }
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(1,0,nums,n,dp);
    }
};