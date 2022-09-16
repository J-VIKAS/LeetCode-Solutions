class Solution {
public:
    
    double dp[1001][1001];
    int n,m;
    double rec( int j, int s, int e,vector<int> &nums, vector<int> &multipliers ){
        
        if ( s > e || j == m ) return 0;
         
           
        if ( dp[s][j] != -1.1 ) return dp[s][j];
        
        return dp[s][j] = max( multipliers[j]*nums[s] + rec(j+1,s+1,e,nums,multipliers),
                    multipliers[j]*nums[e] + rec(j+1,s,e-1,nums,multipliers) );
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        n = nums.size(), m = multipliers.size();
         
        for( int i = 0; i<1001; i++ ){
           for ( int j = 0; j<1001; j++ ){
               dp[i][j] = -1.1;
           }
        }
        
        int x = (rec(0,0,n-1,nums,multipliers));
        return x;
        
    }
};