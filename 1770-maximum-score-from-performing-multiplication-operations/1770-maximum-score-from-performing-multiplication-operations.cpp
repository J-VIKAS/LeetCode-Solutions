class Solution {
public:
    
    int rec( int j, int s, int e, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp ){
        
        if ( s > e || j == multipliers.size() ) return 0;
         
        if ( dp[s][j] != INT_MIN ) return dp[s][j];
        
        return dp[s][j] = max( multipliers[j]*nums[s] + rec(j+1,s+1,e,nums,multipliers,dp),
                    multipliers[j]*nums[e] + rec(j+1,s,e-1,nums,multipliers,dp) );
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return  rec(0,0,n-1,nums,multipliers,dp); 
        
    }
};